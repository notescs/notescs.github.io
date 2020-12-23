---
title: Check if Duplicate Element Exists in an Array
date: "2020-12-23"
template: "post"
category: "Data Structures & Algorithms"
tags:
  - "cpp"
  - "easy"
  - "sort"
  - "hashtable"
description: "Given an array of integers, check if the array contains any duplicates." # Change this
---

<!-- Problem Statement -->

Given an array of integers, check if the array contains any duplicates.

_Example 1_

**Input**: [3, 5, 7, 1, 7]  
**Output**: true  
**Explanation**: 7 is repeated twice.  

_Example 2_

**Input**: [3, 5, 7, 1, 2]  
**Output**: false  
**Explanation**: No element is repeated.

_Example 3_

**Input**: [3, 5, 7, 1, 2, 7, 1, 3, 5]  
**Output**: true

## Approach 1: Brute Force

### Intuition

For every element in the array, check all the subsequent elements and if any of
the subsequent element matches with the current element, return true.

If we do not find any match after checking element, the array contains distinct
integers and false is returned.

### Implementation

```cpp
bool containsDuplicate(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (nums[i] == nums[j]) return true;
        }
    }
    return false;
}
```

### Complexity Analysis

- **Time Complexity**: At the worst case when there are no duplicates, number of
  comparisions = $\frac{N * (N - 1)}{2}$ making time complexity $O(N^2)$, where
  $N$ = number of elements in the array.
- **Space Complexity**: $O(1)$, only constant space is used.

## Approach 2: Sorting

### Intuition

If the array is sorted, same elements appear consecutively. For example, sorting
[3, 5, 7, 1, 2, 7, 1, 3, 5] will yield [1, 1, 2, **3**, **3**, 5, **7**, **7**].
We can use this idea to check for duplicate elements.

### Implementation

```cpp
bool containsDuplicate(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n - 1; ++i) {
        if (nums[i] == nums[i + 1]) return true;
    }
    return false;
}
```

### Complexity Analysis

- **Time Complexity**: $O(NlogN)$ for sorting.
- **Space Complexity**: $O(1)$, only constant space is used.

## Approach 3: Hash Table

### Intuition

While traversing the array, the elements are inserted into a hash table. At each
element, we check if the element is _seen_ before. If it is seen before, there exists
a duplicate element. Since hash table provides $O(1)$
lookup time, overall time complexity does not exceed $O(N)$.

### Implementation

```cpp
bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> seen;
    for (int num : nums) {
        // if the current number is found previously, return true
        if (seen.find(num) != seen.end()) return true;
        seen.insert(num);
    }
    return false;
}
```

### Complexity Analysis

- **Time Complexity**: $O(N)$, at the worst case (no duplicate elements), we have
  to traverse the entire array.
- **Space Complexity**: $O(N)$, at the worst case (no duplicate elements), all the
  elements will be inserted into the hash table.
