---
title: Top k Frequent Words
date: "2020-06-26"
template: "post"
draft: false
slug: "top-k-frequent-words"
category: "Data Structures & Algorithms"
tags:
  - "cpp"
  - "Priority Queue"
  - "Sort"
  - "Difficulty: Medium"
description: "How to use a Custom Comparator in C++ Priority Queue and Solving
Top k Frequent Words"
---

Given a list of words, return the `k` most frequent elements. The answer should
be sorted by frequency from highest to lowest. If two words have the same frequency,
the word with the lower alphabetical order comes first. `k` is always valid,
that is 1 <= `k` <= number of unique words.

For example, for the given list and k = 2,

```shell
["earth", "planet", "hello", "world", "hello", "world"]
```

Return `["hello", "world"]` as they have the highest frequency and sorted according
to the alphabetical order.

## Approach 1: Sorting

### Intuition

In a hashmap, keep the count of the words and then push the words along with their
counts in a list and then sort the list. At last, return the first `k` elements.
For the example above, the hashmap would be:

```text
earth: 1
planet: 1
hello: 2
world: 2
```

After sorting (note the comparator function _comp_ below):

```text
hello: 2
world: 2
earth: 1
planet: 1
```

### Implementation

```cpp
vector<string> topKFrequent(vector<string>& words, int k) {
    unordered_map<string, int> frequency;
    for (string &word: words) {
        ++frequency[word];
    }
    // word, frequency
    vector<pair<string, int>> wordFreq;
    for (const auto &[word, freq]: frequency) {
        wordFreq.push_back({word, freq});
    }
    auto comp = [](const pair<string, int> &a, const pair<string, int> &b) {
        return a.second > b.second || (a.second == b.second && a.first < b.first);  
    };
    sort(wordFreq.begin(), wordFreq.end(), comp);
    vector<string> ret;
    for (int i = 0; i < k; ++i) {
        ret.push_back(wordFreq[i].first);
    }
    return ret;
}
```

### Complexity Analysis

- **Time complexity**: $O(NlogN)$ due to sorting.
- **Space complexity**: $O(N)$.

## Approach 2: Priority Queue

### Using Custom Comparator in Priority Queue in C++ - A Primer

A priority queue is a queue where the elements stay in a certain sorted order. We
can also provide a `Compare` type for custom ordering.

_Defined in header `queue`_

```cpp
template<
    class T,
    class Container = std::vector<T>,
    class Compare = std::less<typename Container::value_type>
> class priority_queue;
```

The compare type should provide strict weak ordering, that is, it should return
true if the first argument comes before the second argument.

Since the priority queue outputs the largest elements first, the elements that
“come before” are actually output last. That is, the front of the queue contains
the “last” element according to the weak ordering imposed by Compare.

By default, in priority queue, the `compare` is `less` that is the largest element
that appears at the top. Using `greater` we can make the smallest element appear
at the top.

```cpp
#include <bits/stdc++.h>
using namespace std;

template<typename T>
void printPriorityQueue(T &pq) {
    while(!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}


int main() {
    priority_queue<int> pq1;
    for (int x: {8, 0, 1, 2, 3, 7}) {
        pq1.push(x);
    }
    printPriorityQueue(pq1); // prints "8 7 3 2 1 0"
    priority_queue<int, vector<int>, greater<int>> pq2;
    for (int x: {8, 0, 1, 2, 3, 7}) {
        pq2.push(x);
    }
    printPriorityQueue(pq2); // prints "0 1 2 3 7 8"
    return 0;
}
```

### Intuition

We have used sorting in approach - 1. Another efficient approach is using a
priority queue. In the priority queue, we will always maintain the top k frequent
words. Note the `comp` function below. If the priority queue size exceeds `k`, we
will pop the topmost element (as it has the lowest count).

### Implementation

```cpp
vector<string> topKFrequent(vector<string>& words, int k) {
    unordered_map<string, int> frequency;
    for (string &word: words) {
        ++frequency[word];
    }

    auto comp = [](const pair<string, int> &a, const pair<string, int> &b) {
        return a.second > b.second || (a.second == b.second && a.first < b.first);  
    };

    priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(comp)> wordFreq (comp);

    for (const auto &[word, freq]: frequency) {
        wordFreq.push({word, freq});
        if (wordFreq.size() > k) wordFreq.pop();
    }

    vector<string> ret;
    while(!wordFreq.empty()) {
        ret.push_back(wordFreq.top().first);
        wordFreq.pop();
    }
    reverse(ret.begin(), ret.end());
    return ret;
}
```

### Complexity Analysis

- **Time complexity**: $O(Nlogk)$ as the priority queue size never exceeds `k`.
- **Space complexity**: $O(N)$.

### Reference

- [Cppreference article on priority\_queue](https://en.cppreference.com/w/cpp/container/priority_queue)
