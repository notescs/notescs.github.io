---
title: Binary Tree Reverse Level Order Traversal
date: 03-07-2020
template: post
draft: false
slug: reverse-level-order-traversal
category: "Data Structures & Algorithms"
tags:
  - "cpp"
  - "binary-tree"
  - "dfs"
  - "bfs"
description: "Given a binary tree, print its reverse level order traversal"
---

Given a binary tree, print its reverse level order traversal. For example, given
this tree -

```text
    3
   / \
  2   8
    /  \
   1    9
```

print -

```text
[
    [1, 9],
    [2, 8],
    [3]
]
```

## Approach - 1: BFS

We can simply perform a BFS traversal and reverse the resulting traversal.

![animated-bfs](/media/Animated_BFS.gif)

_By Blake Matheny - Transferred from <span class="plainlinks"><a class="external text" href="https://en.wikipedia.org">en.wikipedia</a></span> to Commons., <a href="http://creativecommons.org/licenses/by-sa/3.0/" title="Creative Commons Attribution-Share Alike 3.0">CC BY-SA 3.0</a>, <a href="https://commons.wikimedia.org/w/index.php?curid=1864649">Link</a>_

```cpp
vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vector<int>> bfsTraversal;
    // perform bfs
    queue<TreeNode*> q;
    if (root) q.push(root);
    while(!q.empty()) {
        int levelSize = q.size();
        vector<int> curLevelTraversal(levelSize);
        for (int i = 0; i < levelSize; ++i) {
            TreeNode* current = q.front();
            q.pop();
            curLevelTraversal[i] = current -> val;
            if (current -> left) q.push(current -> left);
            if (current -> right) q.push(current -> right);
        }
        bfsTraversal.push_back(curLevelTraversal);
    }
    reverse(bfsTraversal.begin(), bfsTraversal.end());
    return bfsTraversal;
}
```

Time Complexity: `O(N)` due to BFS

Space Complexity: `O(N)` as we are storing nodes in the queue

## Approach - 2: DFS

This problem can also be solved using DFS. It's important that we should visit
the left child first and then the right child. As we go from a parent node to its
child nodes, we increase the `level`. We also store them in a vector and return
its reverse.

```cpp
void dfs(TreeNode *node, vector<vector<int>> &reverseLevelTraversal, int level) {
    if (node == nullptr) return;
    if (level >= reverseLevelTraversal.size()) {
        reverseLevelTraversal.push_back({});
    }
    reverseLevelTraversal[level].push_back(node -> val);
    // increase level if when we go to children nodes
    dfs(node -> left, reverseLevelTraversal, level + 1);
    dfs(node -> right, reverseLevelTraversal, level + 1);
}

vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vector<int>> reverseLevelTraversal;
    // start with level 0
    dfs(root, reverseLevelTraversal, 0);
    reverse(reverseLevelTraversal.begin(), reverseLevelTraversal.end());
    return reverseLevelTraversal;
}
```

Time Complexity: `O(N)` due to DFS

Space Complexity: `O(N)` for recursion stack space

**Exercise**: Use stack to perform DFS.
