---
title: Count Number of Set Bits of an Integer using Brian-Kernighan Method
date: "2020-07-06"
template: "post"
draft: false
slug: "brian-kernighan-algorithm-count-set-bits"
category: "Data Structures & Algorithms"
tags:
  - "cpp"
  - "python"
  - "Bit Manipulation"
  - "Difficulty: Easy"
description: "Count the number of set bits of an integer."
---

Count the number of set bits of an integer.

_Example 1:_  
**Input**: 31  
**Output**: 5  
**Explanation**: Binary representation of 31 is 11111

_Example 2:_  
**Input**: 42  
**Output**: 3  
**Explanation**: Binary representation of 42 is 101010

## Approach 1: Naive

Naive algorithm is to use the binary representation of the number and count the
number of set bits.

C++ code:

```cpp
#include<iostream>
using namespace std;

int countSetBits(int n) {
    int count = 0;
    while (n > 0) {
        count += n & 1; // check if the last bit is set
        n = n >> 1; // right shift by 1 is equivalent to division by 2
    }
    return count;
}


int main() {
    cout << "Number of set bits of " << 31 << " is " << countSetBits(31) << "\n";
    cout << "Number of set bits of " << 42 << " is " << countSetBits(42) << "\n";
    return 0;
}
```

Python code:

```python
def count_set_bits(n):
    count = 0
    while n > 0:
        count += n & 1
        n = n >> 1
    return count

if __name__ == '__main__':
    print('Number of set bits of', 31, 'is', count_set_bits(31))
    print('Number of set bits of', 42, 'is', count_set_bits(42))
```

> In python, we can also use the in-built function `bin`, which takes an integer
> and returns it binary representation in string format. Thus, to calculate the
> number of set bits we only have to count the number of `1` in `bin(n)`:
> `bin(n).count('1')`.

> In C++, we can use `__builtin_popcount` function: `__builtin_popcount(n)`. 

### Complexity Analysis

- **Time Complexity**: $O(log_2N)$ where $N$ is the number
- **Space Complexity**: $O(1)$ as we are not using any extra space

## Approach 2: Brian Kernighan Algorithm

The idea is to use `n = n & (n - 1)` which clears the rightmost set bit. Let us
take a look at some examples.

```text
n           => 101010
n - 1       => 101001
---------------------
n & (n - 1) => 101000
```

`n` is updated to `101000` now.

```text
n           => 101000
n - 1       => 100111
---------------------
n & (n - 1) => 100000
```

`n` is updated to `100000` now.

```text
n           => 100000
n - 1       => 011111
---------------------
n & (n - 1) => 000000
```

`n` is now 0.

Thus, we need only 3 iterations to find the count of set bits.

C++ code:

```cpp
#include<iostream>
using namespace std;

int countSetBits(int n) {
    int count = 0;
    while (n > 0) {
        n = n & (n - 1); // clear the right-most bit
        ++count;
    }
    return count;
}


int main() {
    cout << "Number of set bits of " << 31 << " is " << countSetBits(31) << "\n";
    cout << "Number of set bits of " << 42 << " is " << countSetBits(42) << "\n";
    return 0;
}
```

Python code:

```python
def count_set_bits(n):
    count = 0
    while n > 0:
        n = n & (n - 1)  # clear the right most bit
        count += 1
    return count

if __name__ == '__main__':
    print('Number of set bits of', 31, 'is', count_set_bits(31))
    print('Number of set bits of', 42, 'is', count_set_bits(42))
```

### Complexity Analysis

- **Time Complexity**: $O(log_2N)$ at the worst case when $N$ has all of its bit set.
- **Space Complexity**: $O(1)$ as we are not using any extra space.
