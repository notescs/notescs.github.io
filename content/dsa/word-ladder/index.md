---
title: Word Ladder - Length of Shortest Transformation to Reach a Target Word
date: "2021-06-05"
template: "post"
category: "Data Structures & Algorithms"
tags:
  - "Breadth First Search"
  - "cpp"
  - "python"
  - "Difficulty: Hard"
description: "Find the length of the shortest transformation to reach a target word."
link: https://csposts.com/dsa/word-ladder
---

<!-- Problem Statement -->

A transformation sequence from word `beginWord` to word `endWord` using a dictionary
`wordList` is a sequence of words `beginWord` -> $s_1$ -> $s_2$ -> ... -> $s_k$
such that:

- Every adjacent pair of words differs by a single letter.
- Every $s_i$ for $1 <= i <= k$ is in `wordList`. Note that `beginWord` does not need to be in `wordList`.
- $s_k$ == `endWord`

Given two words, `beginWord` and `endWord`, and a dictionary `wordList`, return
the number of words in the shortest transformation sequence from `beginWord` to
`endWord`, or $0$ if no such sequence exists.

***Example 1***

- **Input**: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
- **Output**: 5  
- **Explanation**: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog",
  which is 5 words long.

***Example 2***

- **Input**: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
- **Output**: 0
- **Explanation**: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.

## Approach 1: Breadth First Search

### Idea

The solution to this problem is similar to this one: [Open the Lock](/dsa/open-the-lock).

Since only one character can be changed a time, we can change the characters one
at a time and check if it exists in the `wordList`. Then, we can assume the word
as a neighbor to the previous word.

For the first example - ["hot","dot","dog","lot","log","cog"], neighbors of "hot"
is "**d**ot" and "**l**ot".

Now, we can run a BFS starting from the `beginWord` and the level where `endWord`
exists, is the length of the shortest transformation sequence.

### Implementation

In C++:

```cpp
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> words (wordList.begin(), wordList.end());
    // if `endWord` doesn't exist, return 0
    if (!words.count(endWord)) return 0;
    unordered_set<string> visited;
    queue<string> q;
    q.push(beginWord);
    visited.insert(beginWord);
    int level = 1;
    while(!q.empty()) {
        int size = q.size();
        while(size--) {
            string s = q.front();
            q.pop();
            // iterate over all the characters of `s`
            for (int i = 0; i < (int)s.length(); ++i) {
                string changed = s;
                // change the characters from 'a' to 'z'
                for (char c = 'a'; c <= 'z'; ++c) {
                    if (c == s[i]) continue;
                    changed[i] = c;
                    // pre-emptively check
                    if (changed == endWord) {
                        return 1 + level;
                    }
                    if (!visited.count(changed) and words.count(changed)) {
                        q.push(changed);
                        visited.insert(changed);
                    }

                }
            } 
        }
        ++level;
    }
    return 0;
}
```

### Complexity Analysis

- **Time Complexity**: $O(N * M * M * 26) = O(NM^2)$ where $N =$ length of 
  `wordList` and $M =$ average length of the strings. Look-up time for `wordList`
  hashset is $O(M)$.
- **Space Complexity**: $O(N * M)$.

## Approach 2: Bi-directional Breadth First Search

### Idea

Since the start node and the target node are fixed, we can run bidirectional
BFS (from both start and end) to improve the time complexity from $O(b^d)$ to
$O(b^{d/2})$ (where $b =$ branching factor of the tree and $d =$ distance of
target from source).

### Implementation

In C++:

```cpp
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> begin({beginWord}),
                          end({endWord}),
                          words(wordList.begin(), wordList.end());
    // if endWord doesn't exist, thus return 0
    if(!words.count(endWord)) return 0;
    int level = 1;
    unordered_set<string> visited;
    while(begin.size() and end.size()) {
        unordered_set<string> next;
        // always consider the smaller set first
        if (begin.size() > end.size()) {
            swap(begin, end);
        }
        for (string s: begin) {
            for (int i = 0; i < (int)s.length(); ++i) {
                string changed = s;
                for (char c = 'a'; c <= 'z'; ++c) {
                    if (c == s[i]) continue;
                    changed[i] = c;
                    // pre-emptively check
                    if (end.count(changed)) {
                        return 1 + level;
                    }
                    if (!visited.count(changed) and words.count(changed)) {
                        next.insert(changed);
                        visited.insert(changed);
                    }

                }
            }
        }
        ++level;
        // we have moved to the next level
        begin = next;
    }
    return 0;
}
```

### Complexity Analysis

- **Time Complexity**: $O(b^{d/2} + b^{d/2}) = O(b^{d/2})$, where $b =$ branching
  factor of the tree and $d =$ distance of target from source.
- **Space Complexity**: $O((N + N) * M) = O(N * M)$ (where $N =$ size of `wordList`),
  required for `begin`, `end`, and `visited` hashsets.
