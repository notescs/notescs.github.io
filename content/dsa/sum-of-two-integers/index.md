---
title: Sum of Two Integers without Arithmetic Operators
date: "2020-12-30"
template: "post"
category: "Data Structures & Algorithms"
tags:
  - "cpp"
  - "Difficulty: Easy"
  - "Bit Manipulation"
description: "Add two integers without using Arithmetic Operators."
---

<!-- Problem Statement -->

Add two integers without using arithmetic operators.

_Example 1_

**Input**: a = 1, b = 5    
**Output**: 6  

## Solution 1: Bit Manipulation

### Intuition

Let us consider, addition between two bits $A$ and $B$ (carry is represented as $C$
and sum is represented as $S$).

A | B | C | S |
--|---|---|---|
0 |	0 |	0 |	0 |
1 |	0 |	0 |	1 |
0 |	1 |	0 |	1 |
1 |	1 |	1 |	0 |

From the truth table clearly, carry, $C = A \& B$ and sum, $S = A \oplus  B$.

This is the concept behind [half-adder](https://en.wikipedia.org/wiki/Half_Adder).

![half-adder](Half_Adder.svg)

### Implementation

```cpp
int getSum(int a, int b) {
    // iterate as long as there is carry
    while (b != 0) {
        // carry: AND operation
        int carry = a & b;
        // sum: XOR operation
        a = a ^ b;
        // left shift carry so as to use in
        // the next step
        b = (unsigned)carry << 1;
    }
    return a;
}
```

## Solution 2: Bit Manipulation (Recursion)

### Implementation

We can also implement the above solution using recursion.

```cpp
int getSum(int a, int b) {
    // recurse as long as there is carry
    if (b != 0) {
        // carry: AND operation
        int carry = a & b;
        // sum: XOR operation
        return getSum(a ^ b, (unsigned)carry << 1);
    }
    return a;
}
```

### Complexity Analysis

- **Time Complexity**: $O(1)$
- **Space Complexity**: $O(1)$

### Credits

The half adder image is taken from [WikiMedia Commons](https://en.wikipedia.org/wiki/File:Half_Adder.svg) (Author: inductiveload, available in [public domain](https://en.wikipedia.org/wiki/en:Public_domain)).
