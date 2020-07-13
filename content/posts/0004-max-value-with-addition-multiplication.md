---
title: Maximum Value of Equation of Ones with Addition and Multiplication Operations
date: "2020-07-05"
template: post
draft: false
slug: max-value-with-addition-multiplication
category: "Data Structures & Algorithms"
tags:
  - "cpp"
  - "python"
  - "dynamic-programming"
  - "easy"
description: "Find the maximum value of an equation of ones with addition and multiplication operations"
---

Given an integer `n`, find the maximum value that can be obtained using
`n` ones and only addition and multiplication operations. Note that, you can insert
any number of valid bracket pairs.

Example:

Input: n = 12  
Output: 81  
Explanation: (1 + 1 + 1) * (1 + 1 + 1) * (1 + 1 + 1) * (1 + 1 + 1) = 81

## Approach: Dynamic Programming

Observe that, in order to find the answer for `n = 5`, we need to consider the
maximum answer obtainable from the answer of `2` and `3`, `1` and `4`. Thus, this
problem has an **optimal substructure** property.

```text
                    5
        /                 \
    op(1, 4)            op(2, 3)
    /  \                /       \
    1   op(2, 2)       op(1, 1)  op(1, 2)
        /      \          / \      /  \
    op(1, 1) op(1, 1)    1   1    1   op(1, 1)
    / \        / \                    / \
   1   1      1   1                  1   1
```

Here, op(m, n) = max(answer for m + answer for n, answer for m * answer for n).

Clearly, from the tree above there are a lot of **overlapping sub-problems**. Owing
to this and optimal substructure property, this problem is an ideal candidate
for dynamic programming.

**Bottom-up approach:**

C++ code:

```cpp
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


long long getMaximumValue(int n) {
    vector<long long> dp(n + 1);
    // dp[i] denotes maximum value that can be obtained from i ones
    dp[0] = 0; // base case: with 0 ones answer is always 0
    dp[1] = 1; // base case: with 1 one answer is 1
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i / 2; ++j) {
            dp[i] = max({dp[i], dp[j] + dp[i - j], dp[j] * dp[i - j]});
        }
    }
    return dp[n];
}


int main() {
    cout << "n = " << 5 << " Maximum possible value " << getMaximumValue(5) << endl;  // prints
    cout << "n = " << 12 << " Maximum possible value " << getMaximumValue(12) << endl;  // prints "81"
    return 0;
}
```

Python code:

```python
def getMaximumValue(n):
    dp = [0] * (n + 1)
    # dp[i] denotes maximum value that can be obtained from i ones
    dp[0] = 0  # base case: with 0 ones answer is always 0
    dp[1] = 1  # base case: with 1 one answer is 1
    for i in range(2, n + 1):
        for j in range(1, i // 2 + 1):
            dp[i] = max(dp[i], dp[j] + dp[i - j], dp[j] * dp[i - j])
    return dp[n]


if __name__ == '__main__':
    print('n =', 5, 'Maximum possible value', getMaximumValue(5))
    print('n =', 12, 'Maximum possible value', getMaximumValue(12))
```

Time Complexity: $O(n ^ 2)$  
Space Complexity: $O(n)$ due to storing states in `dp` array

**Exercise**: Code the top-down approach.
