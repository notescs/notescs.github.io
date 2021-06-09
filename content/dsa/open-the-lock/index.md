---
title: Open the Lock
date: "2021-06-04"
template: "post"
category: "Data Structures & Algorithms"
tags:
  - "Graph"
  - "BFS"
  - "cpp"
  - "Difficulty: Medium"
description: "Minimum number of turns required to open a lock."
---

<!-- Problem Statement -->

You have a lock in front of you with 4 circular wheels. Each wheel has 10 slots:
'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'. The wheels can rotate freely
and wrap around: for example we can turn '9' to be '0', or '0' to be '9'.
Each move consists of turning one wheel one slot (forwards or backwards).

The lock initially starts at '0000', a string representing the state of the 4
wheels.

You are given a list of `deadends` dead ends, meaning if the lock displays any
of these codes, the wheels of the lock will stop turning and you will be
unable to open it.

Given a target representing the value of the wheels that will unlock the lock,
return the minimum total number of turns required to open the lock, or $-1$ if
it is impossible.

***Example 1***

- **Input**: ["0201","0101","0102","1212","2002"], target = "0202"
- **Output**: 6 
- **Explanation**: A sequence of valid moves would be "0000" → "1000" → "1100"
→ "1200" → "1201" → "1202" → "0202". Note that a sequence like "0000" →
  "0001" → "0002" → "0102" → "0202" would be invalid, because the wheels of
  the lock become stuck after the display becomes the dead end "0102".

***Example 2***

- **Input**: deadends = ["0000"], target = "2345"
- **Output**: -1
- **Explanation**: Starting point is a deadend.
  
***Example 3***

- **Input**: deadends = ["8887","8889","8878","8898","8788","8988","7888","9888"], target = "8888"
- **Output**: -1
- **Explanation**: It is impossible to reach without getting stuck.

## Approach 1: Breadth First Search

### Analysis

We can think of this problem as finding the length of the shortest path of graph 
from a starting node to target node. Here the start node is always "0000". The
cost of going from one node to its neighbor is 1. Since the graph is unweighted, we
can use breath first search (BFS) to find the length of the shortest path.

In the implementation below:

- First, insert all the deadend nodes to the visited set
- Initialize a queue with the starting node ("0000")
- Then we perform standard BFS.
  - We find the neighbors by simply adding 1 or subtracting 1 from each character
    of the string (special case: next of 9 is 0 and previous of 0 is 9).
- The answer will be length of the shortest path or simply level of the target
  node in the graph.

<!-- TODO: Example graph from csacademy -->

### Implementation

In C++:

```cpp
int openLock(vector<string>& deadends, string target) {
    unordered_set<string> visited (deadends.begin(), deadends.end());
    // edge case: start is a deadend
    if (visited.count("0000")) return -1;
    if (target == "0000") return 0;
    queue<string> q({"0000"});
    visited.insert("0000");
    int level = 0;
    while(!q.empty()) {
        int size = q.size();
        while(size--) {
            string cur = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i) {
                string prevNeighbor (cur), nextNeighbor (cur);
                // edge: previous of '0' is '9'
                prevNeighbor[i] = cur[i] == '0' ? '9' : cur[i] - 1;
                // edge: next of '9' is '0'
                nextNeighbor[i] = cur[i] == '9' ? '0' : cur[i] + 1;
                for (auto neighbor: {prevNeighbor, nextNeighbor}) {
                    // pre-emptively check, so that we don't have to explore
                    // the other neighbors
                    if (neighbor == target) return 1 + level;
                    if (!visited.count(neighbor)) {
                        q.push(neighbor);
                        visited.insert(neighbor);
                    }
                }
            } 
        }
        ++level;
    }
    return -1;
}
```

### Complexity Analysis

- **Time Complexity**: $O(C^N) = O(10^4) = O(1)$, in the worst case we may have to
  traverse all nodes (number of nodes = $10 * 10 * 10 * 10 = 10000$ ($10$
  characters at each position)).
- **Space Complexity**: $O(10 ^ 4 + 10 ^ 4) = O(1)$, for the set `visited` and the
  queue.

## Approach 2: Bi-directional Breadth First Search

### Analysis

Since the start node and the target node are fixed, we can run bidirectional
BFS (from both start and end) to improve the time complexity from $O(b^d)$ to
$O(b^{d/2})$ (where $b =$ branching factor of the tree and $d =$ distance of
target from source).

### Implementation

In C++:

```cpp
int openLock(vector<string> &deadends, string target) {
    unordered_set<string> begin({"0000"}),
                        end({target}),
                        visited(deadends.begin(), deadends.end());
    // edge case: start is in deadends
    if (visited.count("0000")) return -1;
    if (target == "0000") return 0;
    int level = 0;
    while(begin.size() and end.size()) {
        unordered_set<string> next;
        if (begin.size() > end.size()) {
            swap(begin, end);
        }
        for (string s : begin) {
            for (int i = 0; i < 4; ++i) {
                string prevNeighbor (s), nextNeighbor (s);
                // edge: previous of '0' is '9'
                prevNeighbor[i] = s[i] == '0' ? '9' : s[i] - 1;
                // edge: next of '9' is '0'
                nextNeighbor[i] = s[i] == '9' ? '0' : s[i] + 1;
                for (auto neighbor: {prevNeighbor, nextNeighbor}) {
                    // pre-emptively check, so that we don't have explore rest of
                    // the neighbors
                    if (end.count(neighbor)) {
                        return 1 + level;
                    }
                    if (!visited.count(neighbor)) {
                        next.insert(neighbor);
                        visited.insert(neighbor);
                    }
                }
            }
        }
        ++level;
        begin = next;
    }
    return -1;
}
```

### Complexity Analysis

- **Time Complexity**: $O(b^{d/2} + b^{d/2}) = O(b^{d/2})$, where $b =$ branching
  factor of the tree and $d =$ distance of target from source.
- **Space Complexity**: $O(2 * 10 ^ 4) = O(1)$.
