---
title: Minimum Amount of Coins Required to Make up an Amount # Change this
date: "2021-05-25"
template: "post"
slug: "coin-change"
category: "Data Structures & Algorithms"
tags:
  - "cpp"
  - "python"
  - "Difficulty: Medium"
  - "Dynamic Programming"
description: "You are given an infinite number of coins of different denominations and an amount.
Find the minimum number of coins required to make up that amount."
---

<!-- Problem Statement -->

You are given an infinite number of coins of different denominations and an amount.
Find the minimum number of coins required to make up that amount. If it is not
possible, return -1.

_Example 1_

**Input**:  coins = [1, 2, 3], amount = 10  
**Output**:  4  
**Explanation**: 10 = 3 + 3 + 3 + 1

_Example 2_

**Input**:  coins = [3], amount = 2  
**Output**:  -1  
**Explanation**: Amount 2 cannot be made up using denomination 3

## Solution 1: Dynamic Programming with Memoization (Top Down)

This problem can be solved using dynamic programming.

### Analysis

Let's say we have already found out the minimum number of coins for amount up to
$amount$, then for the last step we can choose any type of coin, $left = amount - coins[i]$ for all $i$.
Now for each $left$, compute the minimum number of coins until $left = 0$. We will
cache the intermediate values for $amount$ so that we don't have to recalculate
it.

### Implementation

In Python:
```python
def coinChange(coins, amount):
    @lru_cache(None)
    def getCoinforAmount(i=amount):
        # no more money left, return 0
        if i == 0:
            return 0
        ans = float('inf')
        for j in range(len(coins)):
            if i >= coins[j]:
                # consider coins[j] and find the value
                ans = min(ans, 1 + getCoinforAmount(i - coins[j]))
        return ans

    ret = getCoinforAmount()
    return -1 if ret == float('inf') else ret
```

In C++:
```cpp
int getCoinForAmount(int i, vector<int> &coins, vector<int> &dp) {
    // base case: no money left, return 0
    if (i == 0) return 0;
    // the result for amount = i is already cached, return the
    // cached result
    if (dp[i] != -1) return dp[i];

    // this will help us to cache the result
    int &ans = dp[i];
    // initialize ans as amount + 1
    ans = dp.size();
    for (int coin: coins) {
        if (i >= coin) {
            // consider `coin` and find the value
            ans = min(ans, 1 + getCoinForAmount(i - coin, coins, dp));
        }
    }
    return ans;
}
int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, -1);
    int ret = getCoinForAmount(amount, coins, dp);
    return ret == amount + 1 ? -1 : ret;
}
```

### Complexity Analysis

- **Time Complexity**: $O(N*amount)$
- **Space Complexity**: $O(amount)$

## Solution 2: Dynamic Programming with Iteration (Bottom Up)

### Intuition

For the bottom up solution, if we have already computed up to $amount$, what would
be the minimum number of coins for $amount + 1$?

### Implementation

In C++:

```cpp
int coinChange(vector<int>& coins, int amount) {
    // assign INF = amount + 1 since maximum number of coins required for `amount` is `amount`
    const int INF = amount + 1;
    // count[i] denotes the minimum number of coins required for amount `i`
    vector<int> count(amount + 1, INF);
    // base case, 0 coins required for amount 0
    count[0] = 0;
    for (int coin : coins) {
        for (int j = coin; j <= amount; ++j) {
            count[j] = min(count[j], 1 + count[j - coin]);
        }
    }
    return count[amount] == INF ? -1 : count[amount];
}
```

In Python:

```python
def coinChange(coins, amount):
    # assign INF = amount + 1 since maximum number of coins required for `amount` is `amount`
    INF = amount + 1
    # count[i] denotes the minimum number of coins required for amount `i`
    count = [INF for _ in range(amount + 1)]
    # base case, 0 coins required for amount 0
    count[0] = 0
    for coin in coins:
        for j in range (coin, amount + 1):
            count[j] = min(count[j], 1 + count[j - coin])

    return -1 if count[amount] == INF else count[amount]
```

### Complexity Analysis

- **Time Complexity**: $O(N*amount)$
- **Space Complexity**: $O(amount)$ required for the table `count`
