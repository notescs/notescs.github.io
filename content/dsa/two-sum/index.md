---
title: Find all the Pairs with Given Sum
date: "2020-12-20"
template: "post"
category: "Data Structures & Algorithms"
tags:
  - "cpp"
  - "easy"
  - "hashing"
  - "binary search"
description: "Given a list of integers, find all pairs with given sum."
---

<!-- Problem Statement -->

Given a list of integers, print all pairs with given sum.

_Example 1_

**Input**: nums = [1, 2, 3, 3, 4, 6, 5], target = 7  
**Output**: [[1, 6], [2, 5], [3, 4], [3, 4]]  
**Explanation**: The pairs that sums up to 7 is [1, 6], [2, 5] and [3, 4]. Note
that, there are two 3 in the nums list, and thus we output it twice. 

## Approach 1: Brute Force

### Intuition

We can simply iterate over all the pairs and check if their sum is equal to
_target_.

### Implementation

```cpp
vector<vector<int>> twoSum(vector<int> nums, int target) {
    int n = nums.size();
    vector<vector<int>> ans;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (nums[i] + nums[j] == target) {
                ans.push_back({nums[i], nums[j]});
            }
        }
    }
    return ans;
}
```

### Complexity Analysis

- **Time Complexity**: $O(N^2)$, where $N$ is the length of input array.
- **Space Complexity**: $O(1)$ extra.

## Approach 2: Binary Search

### Intuition

First sort the list of numbers, and iterate over the numbers as long as the
complement (_target - nums[i]_) is greater than or equal to _nums[i]_. For each of those
numbers, search for the first and last position of complement and push the result 
count (_last position - first position + 1_) number of times. We will explain the
binary search part in a separate post.

### Implementation

```cpp
// returns first position >= x
int getFirstPosition(vector<int> &nums, int x, int low) {
    int n = nums.size();
    int ans = n;
    int high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] >= x) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

vector<vector<int>> twoSum(vector<int> nums, int target) {
    int n = nums.size();
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; ++i) {
        int cur = nums[i];
        int complement = target - cur;
        if (complement < cur) break;
        // make sure complement is after the current element, thus pass (i + 1)
        // as low
        int firstPosition = getFirstPosition(nums, complement, i + 1);
        int lastPosition = getFirstPosition(nums, complement + 1, i + 1) - 1;
        if (firstPosition <= lastPosition) {
            int count = lastPosition - firstPosition + 1;
            // push count number of times
            while (count--) {
                ans.push_back({cur, complement});
            }
        }
    }
    return ans;
}
```

### Complexity Analysis

- **Time Complexity**: $O(NlogN)$ for sorting, and then $O(logN)$ for binary
  search for on average $N/2 * 2 = N$ number of times, effectively making time
  complexity $O(NlogN)$.
- **Space Complexity**: $O(1)$ extra.

## Approach 3 - Two Pointers

### Intuition

After sorting, two pointers _low_ (initialized to 0) and _high_ (initialized to _n - 1_) 
are maintained. If sum of the values
at _low_-th and _high_-th indices is equal to _target_, we push the elements to
_ans_. If the sum is greater than _target_, reduce the _high_ index, else increase
the _low_ index, effectively reducing the search space at every step.

### Implementation

```cpp
vector<vector<int>> twoSum(vector<int> nums, int target) {
    int n = nums.size();
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    int low = 0, high = n - 1;
    while (low < high) {
        if (nums[low] + nums[high] == target) {
            ans.push_back({nums[low], nums[high]});
        }
        if (nums[low] + nums[high] > target) {
            --high;
        } else {
            ++low;
        }
    }
    return ans;
}
```

- **Time Complexity**: $O(NlogN)$ for sorting.
- **Space Complexity**: $O(1)$ extra.

## Approach 4 - Hashing

### Intuition

Iterate over the array and for each element maintain its complement's (_target - element_)
count. Push the pair (current element, complement) _count_ number of times. At
the end, we also push the current element's complement to make it available for
future elements.

### Implementation

```cpp
vector<vector<int>> twoSum(vector<int> nums, int target) {
    int n = nums.size();
    vector<vector<int>> ans;
    unordered_map<int, int> count;
    for (int num: nums) {
        int complement = target - num;
        if (count[num] > 0) {
            for (int c = 0; c < count[num]; ++c) {
                ans.push_back({num, complement});
            }
        }
        ++count[complement];
    }
    return ans;
}
```

- **Time Complexity**: $O(N)$
- **Space Complexity**: $O(N)$ as in the worst case (no valid pair exists), we have
  to store all the elements in the array.
