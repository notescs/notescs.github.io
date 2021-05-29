---
title: Find the Maximum Subarray Sum with Unique Values
date: "2021-05-29"
template: "post"
category: "Data Structures & Algorithms"
tags:
  - "cpp"
  - "python"
  - "Difficulty: Medium"
  - "Two Pointers"
description: "Given an array, find the maximum subarray sum with unique values."
---

<!-- Problem Statement -->

You are given an array of positive integers. Find the maximum subarray sum with
unique values.

An array `b` is called to be a subarray of `a` if it forms a contiguous
subsequence of `a`, that is, if it is equal to `a[l],a[l+1],...,a[r]` for some
`(l,r)`.

_Example 1_

| | |
|--|--|
**Input** |  nums = [1, 2, 3, 5, 3, 1] |
**Output** |  10
**Explanation** | The subarray is [2, 3, 5] having maximum sum and unique values |

_Example 2_

| | |
|--|--|
**Input** |  nums = [1, 2, 3, 5, 3, 1, 4, 5, 1] |
**Output** |  10
**Explanation** | The subarray is [2, 3, 5] or [4, 5, 1] having maximum sum and unique values |

## Approach: Two Pointers

Like many subarray related problems, this can be also be solved using two pointers.

### Intuition

Let's keep two pointers (`left` and `right`) both pointing to the start of the array.
We will also be maintaining a hashmap to keep track of the unique elements considered
in our solution.

As we iterate our sliding window formed by the pointers `left` and `right`, we will
increment the right pointer if it is not already in the solution subarray (sliding
window). If it is present in the sliding window, we will increment the `left` pointer
as long as `nums[right]` is present. The check of presence is computed using a
hashmap which gives an $O(1)$ look-up time complexity.

The value of **sum** is also tracked and whenever we are incrementing the right
pointer, we are adding `nums[right]` to the sum and whenever we are incrementing
the left pointer, we are subtracting `nums[left]` from sum.

### Implementation

In C++:

```cpp
int maximumUniqueSubarray(vector<int>& nums) {
    unordered_set<int> unique;
    int left = 0, right = 0, sum = 0, ans = 0;
    while(right < nums.size()) {
        // if `nums[right]` is already in our solution subarray,
        // remove the `nums[left]` item and increment the left
        // pointer. Essentially, as long as nums[right] is there
        // in our solution subarray we will keep incrementing
        // the left pointer
        if (unique.count(nums[right])) {
            sum -= nums[left];
            unique.erase(nums[left]);
            ++left;
        // `nums[right]` is not in our solution subarray, include it
        } else {
            sum += nums[right];
            unique.insert(nums[right]);
            ans = max(ans, sum);
            ++right;
        }

    }
    return ans;
}
```

In Python:

```python
def maximumUniqueSubarray(nums):
    unique = set()
    left, right, sum, ans = 0, 0, 0, 0
    while right < len(nums):
        # if `nums[right]` is already in our solution subarray,
        # remove the `nums[left]` item and increment the left
        # pointer. Essentially, as long as nums[right] is there
        # in our solution subarray we will keep incrementing
        # the left pointer
        if nums[right] in unique:
            sum -= nums[left]
            unique.remove(nums[left])
            left += 1
        # `nums[right]` is not in our solution subarray, include it
        else:
            sum += nums[right]
            unique.add(nums[right])
            ans = max(ans, sum)
            right += 1
    return ans
```


### Complexity Analysis

- **Time Complexity**: $O(N)$ where $N =$ size of the array
- **Space Complexity**: $O(N)$, in the worst case all the elements are unique, and
  we may have to store all of them in the hashmap
