---
title: Count the Number of Set Bits for Every Number from 0 to n
date: "2020-12-25"
template: "post"
category: "Data Structures & Algorithms"
tags:
  - "cpp"
  - "medium"
  - "bit-manipulation"
  - "dynamic-programming"
description: "Given a number n, count the number of 1's in the binary representation
of each number from 0 to n."
---

<!-- Problem Statement -->
Given a number n, count the number of 1's in the binary representation
of each number from 0 to n.

_Example 1_  
**Input**: 6  
**Output**: [0, 1, 1, 2, 1, 2, 2]  
**Explanation**: Number of 1 in binary representation of 6 is 2, 5 is 2, 4 in 1
and so on.

## Approach 1: Naive

### Intuition

Using the approaches discussed in [this post](/posts/brian-kernighan-algorithm-count-set-bits),
we can run a loop from _0_ to _n_ and calculate the number of set bits. In the following
example, we are using the Brian-Kernighan algorithm to count the number of set
bits.

### Implementation

```cpp
int countOfSetBits(int x) {
    int count = 0;
    while (x > 0) {
        x = x & (x - 1);
        ++count;
    }
    return count;
}
vector<int> countBits(int num) {
    vector<int> ans (num + 1);
    for (int i = 0; i <= num; ++i) {
        ans[i] = countOfSetBits(i);
    }
    return ans;
}
```

### Complexity Analysis

- **Time Complexity**: $O(Nlog_2N)$.
- **Space Complexity**: $O(1)$ extra, if the returned vector _ans_ is not considered.
  Considering _ans_, the space complexity is $O(N)$.

## Approach 2: Dynamic Programming

### Intuition

Let us observe how we can get to 2 and 3 from 1.
1. To get 2 (binary representation _10_), _1_ is right shifted once.
2. To get 3 (binary representation _11_), _1_ is right shifted once (that is, we get 2 (_10_)) 
   and then 1 is added.

This is true for all positions of the binary representation. So, we can generalize that -
- One bit contributed by the least significant bit (right most bit), which can be obtained
  by checking it the number is odd or even
- A number has same number of set bits as its right shifted version (for example,
  1110010 has same number of set bits as 111001). The right shifted version can be obtained
  by dividing the current number by 2 or using the bitwise operator `>>`.

Considering these points we can build the bottom up dp table.


### Implementation

```cpp
vector<int> countBits(int n) {
    // initialize dp with all values set to 0
    // dp[i] denotes number of set bits of i
    vector<int>dp(n + 1, 0);
    // dp[0] = 0 as number of set bits of 0 is 0
    for (int i = 1; i <= n; ++i) {
        dp[i] = dp[i >> 1] + (i & 1);
        // note that, i >> 1 is equivalent to i / 2
        // i & 1 is equivalent to i % 2, so we are checking if i is odd or not by i & 1
    }
    return dp;
}
```

### Complexity Analysis

- **Time Complexity**: $O(N)$, the loop only runs for $N$ times.
- **Space Complexity**: $O(N)$ considering the returned vector _dp_.


## Approach 3: Dynamic Programming using Brian Kernighan Algorithm

### Intuition

The idea is to use $x \& (x - 1)$ technique to clear the right most set bit.
Thus, number of set bits of $x$ = number of set bits of $x \& (x - 1)$ + 1.
More details can be found in [this post](/posts/brian-kernighan-algorithm-count-set-bits).

### Implementation

```cpp
vector<int> countBits(int n) {
    // initialize dp with all values set to 0
    // dp[i] denotes no of set bits of i
    vector<int>dp(n + 1, 0);
    // dp[0] = 0 as number of set bits of 0 is 0
    for (int i = 1; i <= n; ++i) {
        dp[i] = dp[i & (i - 1)] + 1;
    }
    return dp;
}
```

### Complexity Analysis

- **Time Complexity**: $O(N)$, the loop only runs for $N$ times.
- **Space Complexity**: $O(N)$ considering the returned vector _dp_.
