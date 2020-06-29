---
title: Using Custom Comparator in C++ Priority Queue
date: "2020-06-26"
template: "post"
draft: false
slug: "custom-compare-priority-queue-cpp"
category: "cpp"
tags:
  - "cpp"
  - "priority queue"
description: ""
---

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

Since the priority queue outputs largest elements first, the elements that
"come before" are actually output last. That is, the front of the queue contains
the "last" element according to the weak ordering imposed by Compare.

## Example: Top k Frequent Words

Given a list of words, return the `k` most frequent elements. The answer should
be sorted by frequency from highest to lowest. If two words have the same
frequency, then the word with the lower alphabetical order comes first. `k` is
always valid, that is 1 <= k <= number of unique words.

For example, for the given list and k = 2,

```python
["hello", "world", "hello", "earth", "planet", "world"]
```

Return `["hello", "world"]` as they have the highest frequency and sorted
according to the alphabetical order.

### Approach 1: Sorting

In a hashmap, keep the count of the words and then push the words along with
their counts in a list and then sort the list. At last, return the first `k`
elements.

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

Time complexity: `O(NlogN)` due to sorting

Space complexity: `O(N)`

## Approach 2: Priority Queue

Another efficient approach is using a priority queue. In the priority queue we
will always maintain the top k frequent words. Note the `comp` function below.
If the priority queue size exceeds `k`, we will pop the top most element (as it
has the lowest count).

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

Time complexity `O(Nlogk)` as the priority queue size never exceeds `k`.

Space complexity `O(N)`.

## Reference

- [Cppreference article on priority_queue](https://en.cppreference.com/w/cpp/container/priority_queue)
