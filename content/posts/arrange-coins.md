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

Given a total of `n` coins find total number of full staircase rows that can be
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

Since this is an increasing function of k, we can use binary search to solve this
problem.

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
k*(k + 1) / 2 <= n
\implies k^2 + k <= 2*n
\implies k^2 + k - 2*n <=0
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
