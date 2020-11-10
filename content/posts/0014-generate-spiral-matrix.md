---
title: Generate Spiral Matrix
date: "2020-11-08"
template: "post"
draft: false
slug: generate-spiral-matrix
category: "Data Structures & Algorithms"
tags:
  - "cpp"
  - "medium"
  - "Matrix"
description: "Given a positive integer n, generate a square matrix filled with elements from 1 to $n^2$ in spiral order."
---

**Problem**

Given a positive integer n, generate a square matrix filled with elements from 1 to $n^2$ in spiral order.

**Examples**

Input: n = 4

Output:

1 2 3 4

12 13 14 5

11 16 15 6

10 9 8 7 

**Solution**

In this problem, we can traverse the matrix layer by layer. A single layer traversal consists of -

- traversing from top left to top right (first row in the layer)
- traversing from top right to bottom right (last column in the layer)
- traversing from bottom right to bottom left (last row in the layer) and,
- traversing from bottom left to top left (first column in the layer)

One such example is shown below:

- traversing the first row in the layer

**1 2 3 4**

12 13 14 5

11 16 15 6

10 9 8 7 

- traversing the last column in the layer

1 2 3 4

12 13 14 **5**

11 16 15 **6**

10 9 8 **7**

- traversing the last row in the layer

1 2 3 4

12 13 14 5

11 16 15 6

**10 9 8** 7 

- traversing the first column in the layer

1 2 3 4

**12** 13 14 5

**11** 16 15 6

10 9 8 7 

```cpp
vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> matrix(n, vector<int>(n));
    int rowStart = 0, rowEnd = n - 1, columnStart = 0, columnEnd = n - 1;
    int cur = 1;
    while (rowStart <= rowEnd and columnStart <= columnEnd) {
        // traversing from top left to top right (first row in the layer)
        for (int c = columnStart; c <= columnEnd; ++c) {
            matrix[rowStart][c] = cur++;
        }
        ++rowStart;
        // traversing from top right to bottom right (last column in the layer)
        for (int r = rowStart; r <= rowEnd; ++r) {
            matrix[r][columnEnd] = cur++;
        }
        --columnEnd;
        // traversing from bottom right to bottom left (last row in the layer)
        for (int c = columnEnd; c >= columnStart; --c) {
            matrix[rowEnd][c] = cur++;
        }
        --rowEnd;
        // traversing from bottom left to top left (first column in the layer)
        for (int r = rowEnd; r >= rowStart; --r) {
            matrix[r][columnStart] = cur++;
        }
        ++columnStart;
    }
    return matrix;
}
```

**Time Complexity**: $O(n^2)$

**Space Complexity**: $O(1)$
