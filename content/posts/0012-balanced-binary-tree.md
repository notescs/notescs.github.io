---
title: Check if a Binary Tree is Balanced or Not
date: "2020-11-06"
template: "post"
slug: "balanced-binary-tree"
category: "Data Structures & Algorithms"
tags:
  - "cpp"
  - "Binary Tree"
  - "easy"
description: "Given root of a binary tree, check if it is balanced or not."
---

We define a height-balanced binary tree as a "binary tree whose the height of left and right subtree of every node doesn't differ by more than 1".
For example, the given binary tree is balanced:

```text
    1
   / \
  2   3
     / \
     4  5
```

Whereas, this is an unbalanced binary tree:
```text
    1
   / \
  2   3
     / \
     4  5
       / \
       6  7
```

## Recursive Solution (by calculating heights)

As stated in the definition, we can recursively check all the nodes' left and right subtree height and check if it differs by more than 1. In the following code, the function height calculates the height of the corresponding node. The height of a node is defined as the number of edges from the node to the deepest leaf.

```cpp
int height(TreeNode* root) {
    if (root == nullptr) return 0;
    else return max(height(root->left), height(root->right)) + 1;
}
bool isHeightBalanced(TreeNode* root) {
    if (root == nullptr) return true;
    else if (abs(height(root->left) - height(root->right)) > 1) return false;
    else return isHeightBalanced(root->left) and isHeightBalanced(root->right);
}
```

- **Time Complexity**: $O(n^2)$ where $n$ is the number of nodes in the binary tree. Since we calculate the height of each node and the function height can take as many as $n$ recursion calls to calculate the height, the time complexity is $n * n = n^2$.
- **Space Complexity**: $O(h)$ where $h$ is the height of the binary tree, on average $h = log(n)$, however for a skewed tree $h = n$. The space is required for the stacks in recursion calls.

## Recursive Solution (including the logic in height function)

Instead of calculating height for each node, we can include the logic in the `height` function itself.

```cpp
int height(TreeNode *root) {
    if (root == nullptr) return 0;
    else {
        int leftSubtreeHeight = height(root->left);
        if (leftSubtreeHeight == -1) return -1;
        int rightSubtreeHeight = height(root->right);
        if (rightSubtreeHeight == -1) return -1;
        // if left and right subtree height differs by more than 1
        // return -1, which signifies this is a unbalanced tree
        if (abs(leftSubtreeHeight - rightSubtreeHeight) > 1) return -1;
        return 1 + max(leftSubtreeHeight, rightSubtreeHeight);
    }
}
    
bool isHeightBalanced(TreeNode* root) {
    if (root == nullptr) return true;
    if (height(root) != -1) return true;
    else return false;
}
```

- **Time Complexity**: $O(n)$ where $n$ is the number of nodes in the binary tree.
- **Space Complexity**: $O(h)$ where $h$ is the height of the binary tree, on average $h = log(n)$, however for a skewed tree $h = n$. The space is required for the stacks in recursion calls.

## Iterative Solution

If we observe the `height` function in the above solution, a postorder traversal is used (recursively visit left and right subtree of a node first and then process the current node. As such, an iterative postorder traversal can be used to get the height of left and subtree and check if the node is height-balanced.

```cpp
bool isHeightBalanced(TreeNode* root) {
    TreeNode* curNode = root;
    TreeNode* prevNode = nullptr;
    stack<TreeNode*> toTraverse;
    unordered_map<TreeNode*, int> heights;

    while (curNode or !toTraverse.empty()) {
        while (curNode) {
            toTraverse.push(curNode);
            // traverse as far left as possible
            curNode = curNode -> left;
        }
        curNode = toTraverse.top();
        // if curNode doesn't have a right child or last visited node was right
        // child of this node
        if (curNode -> right == nullptr or prevNode == curNode -> right) {
            int leftSubtreeHeight = heights[curNode -> left];
            int rightSubtreeHeight = heights[curNode -> right];
            if (abs(leftSubtreeHeight - rightSubtreeHeight) > 1) return false;
            heights[curNode] = 1 + max(leftSubtreeHeight, rightSubtreeHeight);
            // these values are no longer required, so delete them
            heights.erase(curNode -> left);
            heights.erase(curNode -> right);
            prevNode = curNode;
            curNode = nullptr;
            toTraverse.pop();
        } else {
            curNode = curNode -> right;
        }
    }
    return true;
}
```

- **Time Complexity**: $O(n)$ where $n$ is the number of nodes in the binary tree.
- **Space Complexity**: $O(h)$ where $h$ is the height of the binary tree, on average $h = log(n)$, however for a skewed tree $h = n$. The space is required for the `toTraverse` stack.
