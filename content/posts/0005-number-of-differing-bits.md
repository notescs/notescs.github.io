---
title: Number of Differing Bits 
date: "2020-07-07"
template: "post"
draft: false
slug: "number-of-differing-bits"
category: "Data Structures & Algorithms"
tags:
  - "cpp"
  - "python"
  - "Bit Manipulation"
  - "Difficulty: Easy"
description: "Given two integers count the number of positions where there bit
representation differ."
---

Given two integers count the number of positions where their bit
representation differs. A simple approach is to use their binary representation and
compare them. They can also be compared on the fly.

## Approach : XOR

Let's take a look at the truth table of XOR operation:

A | B | Y = A ^ B |
--|---|-----------|
0 | 0 |     0     |
0 | 1 |     1     |
1 | 0 |     1     |
1 | 1 |     1     |

It is evident that XOR operation gives 1 if the two bits are different (see row
2 and 3). So, the set bits in A ^ B will be the ones where the binary representation
of A and B differ.

For example,

```text
A = 19 => 10011
B = 10 => 01010
---------------
A ^ B =>  11001
```

Thus, the number of set bits in A ^ B will give the desired answer. We can use
[Brian-Kernighan method](https://notescs.gitlab.io/brian-kernighan-algorithm-count-set-bits)
to count the number of set bits.

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

int countDifferntBits(int a, int b) {
    return countSetBits(a ^ b);
}

int main() {
    cout << "Number of different bits of " << 19 << " and " << 10 << " is " << countDifferntBits(19, 10) << "\n";
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

def count_different_bits(a, b):
    return count_set_bits(a ^ b)

if __name__ == '__main__':
    print('Number of different bits of', 19, 'and', 10, 'is', count_different_bits(19, 10))
```

Time Complexity: $O(log(min(a, b)))$  
Space Complexity: $O(1)$

**Exercise**: Code the naive solution.
