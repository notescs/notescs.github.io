---
title: Find One Missing Number in a Range
date: "2020-12-26"
template: "post"
category: "Data Structures & Algorithms"
tags:
  - "cpp"
  - "Difficulty: Easy"
  - "Sort"
  - "Bit Manipulation"
  - "Math"
  - "Hash Table"
description: "Given an array containing n distinct integers in the range [0, n],
one number is missing from the array. Find the missing number."
---

<!-- Problem Statement -->

Given an array containing *n* distinct integers in the range [0, n], one number is
missing from the array. Find the missing number.

_Example 1_  
**Input**: [0, 2, 3]  
**Output**: 1  
**Explanation**: 1 is missing from the array.

_Example 2_  
**Input**: [0, 2, 1]  
**Output**: 3  
**Explanation**: _n = 3_, since size of the array is 3. 3 is missing from the array.

## Solution 1: Sort

### Intuition

Sorting the array will result in _0, 1, 2, 3, ..., n_ this order with one number missing.
In other words, we can say, _nums[i]_ will be equal to _i_ (index). If it is not equal, we
can say that the current number is missing. Even after looping over the entire
array, if we don't find the missing number, the missing number will be _nums.size()_.

### Implementation

```cpp
int missingNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    for (int i = 0; i < (int)nums.size(); ++i) {
        if (nums[i] != i) {
            return i;
        }
    }
    return (int)nums.size();
}
```

### Complexity Analysis

- **Time Complexity**: $O(nlog_2n)$ for sorting and $O(n)$ for the loop. Thus, overall
  time complexity $O(nlog_2n)$.
- **Space Complexity**: $O(1)$, as we are using constant space.

## Solution 2: Hash Table

### Intuition

We can simply check if all the numbers from _0_ to _n_ exists in the array. We can
efficiently do this checking using a hash table. Since hash table has a lookup
time complexity of $O(1)$, the overall time complexity never exceeds $O(n)$.

### Implementation

```cpp
int missingNumber(vector<int>& nums) {
    unordered_set <int> numSet (nums.begin(), nums.end());
    int expectedNums = nums.size();
    for (int i = 0; i <= expectedNums; ++i) {
        if (numSet.find(i) == numSet.end()) {
            return i;
        }
    }
    __builtin_unreachable(); // unreachable code
    // replace by __assume(false) if you are using Microsoft Visual Studio C++
}
```

### Complexity Analysis

- **Time Complexity**: $O(n)$.
- **Space Complexity**: $O(n)$ for storing the elements in the hash table.

## Solution 3: XOR

### Intuition

XOR is its own inverse. We can use this self-inverse property of XOR operations
to find the missing number.

Let's assume a number k is missing. We can show that, all the numbers will get cancelled except
k.

(0 ^ 1 ^ 2 ^ ... ^ n) ^ (nums[0] ^ nums[1] ^ ... ^ nums[n - 1])  
= (0 ^ 0) ^ (1 ^ 1) ^ (2 ^ 2) ^ ... ^ k ^ ... ^ (n ^ n) [XOR operations are
associative, _k_ will not have a corresponding element from _nums_]  
= 0 ^ 0 ^ 0 ^ ... ^ k ^ ... ^ 0  
= k

### Implementation

```cpp
int missingNumber(vector<int>& nums) {
    int missingNum = nums.size();
    for (int i = 0; i < (int)nums.size(); ++i) {
        missingNum ^= i ^ nums[i];
    }
    return missingNum;
}
```

### Complexity Analysis

- **Time Complexity**: $O(n)$, the _for_ loop runs for _n_ times.
- **Space Complexity**: $O(1)$, we are using constant space.

## Solution 4: Sum of n Natural Numbers

### Intuition

We can obtain the missing number by summing all number from 0 to n and then subtract
sum of array elements from it. The formula $n * (n + 1) / 2$ can be used to calculate
_0 + 1 + 2 + ... + n_.

### Implementation

```cpp
int missingNumber(vector<int>& nums) {
    int n = nums.size();
    int withoutMissingSum = n * (n + 1) / 2;
    // calculate sum of all the elements of nums
    int withMissingSum = accumulate(nums.begin(), nums.end(), 0);
    return withoutMissingSum - withMissingSum;
}
```

### Complexity Analysis

- **Time Complexity**: $O(n)$.
- **Space Complexity**: $O(1)$.


## Solution 5: Calculating Offset

### Intuition

One issue of the above approach is that for big $n$, the sum can overflow. Thus,
instead of summing we can calculate the offset while looping over the array and
at the end subtract _offset_ from _nums.size()_.

### Implementation

```cpp
int missingNumber(vector<int>& nums) {
    int offset = 0;
    for (int i = 0; i < (int)nums.size(); ++i) {
        offset += nums[i] - i;
    }
    return nums.size() - offset;
}
```

### Complexity Analysis

- **Time Complexity**: $O(n)$.
- **Space Complexity**: $O(1)$, we are using constant space.
