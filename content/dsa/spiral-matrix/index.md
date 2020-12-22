---
title: Print Matrix in Spiral Order
date: "2020-12-22"
template: "post"
category: "Data Structures & Algorithms"
tags:
  - "cpp"
  - "medium"
  - "Matrix"
description: "Given a matrix, print all elements in spiral order."
---

<!-- Problem Statement -->

Given a matrix, print all elements in spiral order.

_Example 1_

**Input**: matrix = [[0, 1, 2], [3, 4, 5], [6, 7, 8], [9, 10, 11]]  
**Output**:  [0, 1, 2, 5, 8, 11, 10, 9, 6, 3, 4, 7]  
**Explanation**: We are traversing this matrix spirally:  
0 1 2  
3 4 5  
6 7 8  
9 10 11

## Approach: Using 4 Variables for Traversal

### Intuition

This problem is similar to [Generate Spiral Matrix](/posts/generate-spiral-matrix).
However, in the said problem, the output matrix will always be a square one and thus
all the following 4 steps will be completed in each layer of traversal:

- traversing from top left to top right (first row in the layer)
- traversing from top right to bottom right (last column in the layer)
- traversing from bottom right to bottom left (last row in the layer) and,
- traversing from bottom left to top left (first column in the layer)

However for this problem, some matrices exist where only the first 2 steps are
required for the last layer of traversal and thus we need to add two conditions
such that the last 2 steps are not duplicated for the last layer of traversal.

### Implementation

```cpp
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int n = matrix.size(), m = matrix[0].size();
    int rowStart = 0, rowEnd = n - 1, columnStart = 0, columnEnd = m - 1;
    vector<int> spiralOrderTraversal;
    while (rowStart <= rowEnd and columnStart <= columnEnd) {
        // traversing from top left to top right (first row in the layer)
        for (int c = columnStart; c <= columnEnd; ++c) {
            spiralOrderTraversal.push_back(matrix[rowStart][c]);
        }
        ++rowStart;
        // traversing from top right to bottom right (last column in the layer)
        for (int r = rowStart; r <= rowEnd; ++r) {
            spiralOrderTraversal.push_back(matrix[r][columnEnd]);
        }
        --columnEnd;
        // traversing from bottom right to bottom left (last row in the layer)
        // note the condition below
        if (rowStart <= rowEnd) {
            for (int c = columnEnd; c >= columnStart; --c) {
                    spiralOrderTraversal.push_back(matrix[rowEnd][c]);
            }
        }
        --rowEnd;
        // traversing from bottom left to top left (first column in the layer)
        // note the condition below
        if (columnStart <= columnEnd) {
            for (int r = rowEnd; r >= rowStart; --r) {
                spiralOrderTraversal.push_back(matrix[r][columnStart]);
            }
        }
        ++columnStart;
    }
    return spiralOrderTraversal;
}
```

We can also achieve the same spiral order traversal using recursion:

```cpp
void traverseLayer(int rowStart, int rowEnd, int columnStart, int columnEnd, vector<int> &spiralOrderTraversal, vector<vector<int>> &matrix) {
    if (rowStart > rowEnd) return;
    // traversing from top left to top right (first row in the layer)
    for (int c = columnStart; c <= columnEnd; ++c) {
        spiralOrderTraversal.push_back(matrix[rowStart][c]);
    }
    ++rowStart;
    if (columnStart > columnEnd) return;
    // traversing from top right to bottom right (last column in the layer)
    for (int r = rowStart; r <= rowEnd; ++r) {
        spiralOrderTraversal.push_back(matrix[r][columnEnd]);
    }
    --columnEnd;
    // traversing from bottom right to bottom left (last row in the layer)
    // note the condition below
    if (rowStart > rowEnd) return;
    for (int c = columnEnd; c >= columnStart; --c) {
            spiralOrderTraversal.push_back(matrix[rowEnd][c]);
    }
    --rowEnd;
    // traversing from bottom left to top left (first column in the layer)
    // note the condition below
    if (columnStart > columnEnd) return;
    for (int r = rowEnd; r >= rowStart; --r) {
        spiralOrderTraversal.push_back(matrix[r][columnStart]);
    }
    ++columnStart;
    traverseLayer(rowStart, rowEnd, columnStart, columnEnd, spiralOrderTraversal, matrix);
}
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int n = matrix.size(), m = matrix[0].size();
    int rowStart = 0, rowEnd = n - 1, columnStart = 0, columnEnd = m - 1;
    vector<int> spiralOrderTraversal;
    traverseLayer(rowStart, rowEnd, columnStart, columnEnd, spiralOrderTraversal, matrix);
    return spiralOrderTraversal;
}
```

### Complexity Analysis

- **Time Complexity**: $O(N * M)$, where $N = $number of rows, $M = $number of columns.
- **Space Complexity**: $O(1)$ extra, if the returned vector is considered, space complexity is $O(N * M)$.
