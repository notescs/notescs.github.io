---
title: Maximize Sum of Subsequence with Condition
date: "2021-02-05"
template: "post"
draft: true # Change this
category: "Data Structures & Algorithms"
tags:
  - "cpp"
  - "Difficulty: Medium"
  - "Binary Search"
description: "Given an array of integers, maximize sub of subsequence such that
the sum of any two elements in the subsequence is greater than or equal to any
other element."
---

<!-- Problem Statement -->

Given an array of integers, maximize sub of subsequence such that
the sum of any two elements in the subsequence is greater than or equal to any
other element. Return the sum of the subsequence.

_Example 1_

**Input**: A = [4, 4, 4, 10, 5]  
**Output**: 17  
**Explanation**: Maximum sum = 17 for the subsequence [4, 4, 4, 5]. An invalid
subsequence would be [4, 4, 10, 5] since 4 + 5 < 10 and 4 + 4 < 10.

## Solution: Binary Search with Prefix Sum

### Analysis

Let us take a sorted array [1, 2, 3, 10, 10, 10, 10, 10, 10, 40].

Now, let us consider the valid subarrays according to the question:

- [**1, 2, 3**, 10, 10, 10, 10, 10, 10, 40]
- [1, **2, 3**, 10, 10, 10, 10, 10, 10, 40]
- [1, 2, **3, 10, 10, 10, 10, 10, 10**, 40]
- [1, 2, 3, **10, 10, 10, 10, 10, 10**, 40]
- [1, 2, 3, 10, **10, 10, 10, 10, 10**, 40]
- [1, 2, 3, 10, 10, **10, 10, 10, 10**, 40]
- [1, 2, 3, 10, 10, 10, **10, 10, 10**, 40]
- [1, 2, 3, 10, 10, 10, 10, **10, 10**, 40]
- [1, 2, 3, 10, 10, 10, 10, 10, **10, 40**]

We can clearly observe that the index of last valid element can be found by summing
the left most two elements and then binary searching for the last element which
is less than or equal to the sum of the left most two elements.

We can improve calculating sum of a subarray using a prefix sum array.

Hence, the algorithm -

1. Sort the array
2. Calculate prefix sum of the array
3. Iterate over the array and find the last index of the element which is less than
   or equal to the sum of two left most elements.
4. The sum of such valid subarray can be calculated using the prefix sum array.
5. Return the maximum sum.

### Implementation

```cpp
int maxSubsequence(vector<int> a) {
    sort(a.begin(), a.end());
    int n = a.size();
    vector<int> pref(n);
    // calculate prefix sum
    pref[0] = a[0];
    for (int i = 1; i < n; ++i) {
        pref[i] = pref[i - 1] + a[i];
    }
    int ret = 0;
    for (int i = 0; i < n - 1; ++i) {
        int curMax2 = a[i] + a[i + 1];
        // search for the last index of the element which is <= curMax2
        int pos = upper_bound(a.begin() + i, a.end(), curMax2) - 1 - a.begin();
        int sum;
        if (i == 0) {
            sum = pref[pos];
        } else {
            sum = pref[pos] - pref[i - 1];
        }
        ret = max(ret, sum);
    }
    return ret;
}


int main() {
    assert(maxSubsequence({4, 4, 4, 10, 5}) == 17);
    assert(maxSubsequence({2, 2, 2, 2}) == 8);
    assert(maxSubsequence({1, 2, 10, 12, 13}) == 35);
    assert(maxSubsequence({1, 2, 3, 10, 10, 10, 10, 10, 10, 40}) == 63);
}
```

### Complexity Analysis

- **Time Complexity**: $O(NlogN)$ for sorting and then $(N - 1)$ binary search each
  having time complexity $O(logN)$ making overall time complexity $O(NlogN)$.
- **Space Complexity**: $O(N)$ extra for the prefix array.
