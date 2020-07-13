---
title: Maximum Height When Coins are Arranged in Staircase Fashion
date: "2020-07-04"
template: post
draft: false
slug: arrange-coins-in-staircase
category: "Data Structures & Algorithms"
tags:
  - "cpp"
  - "python"
  - "binary-search"
  - "math"
  - "easy"
description: "Solve the problem using binary search and math"
---

Given a total of `n` coins find the total number of full staircase rows that can be
built.

Staircase rows are those where `i`-th row has `i` coins.

For example, given n = 6, return 3 as you can form staircase like this:

```text
*
* *
* * *
```

Given n = 9, return 3.

```text
*
* *
* * *
* * *
```

Note that, the 4th row is invalid as it doesn't have 4 coins.

## Approach - 1: Binary Search

To build a staircase till k-th row, we need:

$1 + 2 + 3 + ... + k = k*(k + 1) / 2$ coins.

So we need to find maximum k such that, $k*(k + 1) / 2 <= n$.

Since $n$ is an increasing function of $k$, we can use binary search to solve this
problem.

We initialize `low` and `high` as `0` and `n` respectively. In each step, we calculate
the value of coins required using the formula $n = k*(k + 1) / 2$ where `k` is the
middle element between `low` and `high`. If the required coins are greater than
`n` the value of `high` is updated to `k - 1` and if its less than `n`, the value
of `low` is updated to `k + 1`. Since we reduce the search space by half at each
iteration, the time complexity is $O(logN)$, where N is the number of coins.

C++ code:

```cpp
#include <iostream>
using namespace std;

int arrangeCoins(int n) {
    long low = 0, high = n;
    while (low <= high) {
        long k = low + (high - low) / 2;
        long cur = k * (k + 1) / 2;

        if (cur == n) return (int)k;

        if (n < cur) {
            high = k - 1;
        } else {
            low = k + 1;
        }
    }
    return (int)high;
}

int main() {
    cout << 6 << " " << arrangeCoins(6) << endl;
    cout << 9 << " " << arrangeCoins(9) << endl;
}
```

Python code:

```python
def arrangeCoins(n):
    low = 0
    high = n
    while low <= high:
        k = low + (high - low) // 2
        cur = k * (k + 1) // 2

        if cur == n: return k

        if n < cur:
            high = k - 1
        else:
            low = k + 1
    return high

if __name__ == '__main__':
    print(6, arrangeCoins(6))  # n = 6, prints 3
    print(9, arrangeCoins(9))  # n = 9, prints 3
```

Time Complexity: $O(logN)$ due to binary search

Space Complexity: $O(1)$

## Approach - 2: Math

We have formulated the equation:

$$
\begin{aligned}
k*(k + 1) / 2 &<= n\\
k^2 + k &<= 2*n\\
k^2 + k - 2*n &<=0
\end{aligned}
$$

We can use Sridharacarya's formula to solve this equation:

$$
k = \frac{-1 + \sqrt{1 + 8n}}{2}
$$

C++ code:

```cpp
#include <iostream>
#include <cmath>
using namespace std;

int arrangeCoins(int n) {
    int(-1 + sqrt(1 + (long)8 * n)) / 2;
}

int main() {
    cout << 6 << " " << arrangeCoins(6) << endl;
    cout << 9 << " " << arrangeCoins(9) << endl;
}
```

Python code:

```python
def arrangeCoins(n):
    return int((-1 + ((1 + 8 * n) ** 0.5)) / 2)

if __name__ == '__main__':
    print(6, arrangeCoins(6))  # n = 6, prints 3
    print(9, arrangeCoins(9))  # n = 9, prints 3
```

Time Complexity: $O(1)$

Space Complexity: $O(1)$
