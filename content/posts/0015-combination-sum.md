---
title: Find Combinations of a List Whose Sum is Equal to a Target
date: "2020-12-19"
template: "post"
draft: false
slug: "combination-sum"
category: "Data Structures & Algorithms"
tags:
  - "cpp"
  - "medium"
  - "backtracking"
description: "Given a list of distinct integers, find all the possible combinations which sums up to a target."
---

Given a list of distinct integers _nums_ and a target integer _target_, find all
the possible combinations of _nums_ which sums up to _target_. You may use a number
more than once. 

## Approach: Backtracking

### Analysis

Since we have to find all possible combinations, we can use backtracking to solve
the problem. There are 2 possible cases for all the elements in the array: either
it can be added to combination or not.

In the _findSolution_ function below, _idx_ (current index)
and _currentSolution_ is passed.

1. If _target_ is 0, we have found a solution, thus push _currentSolution_ to the
   _ans_ 2D vector.
2. Otherwise - 
   1. Loop from current index (not _idx + 1_ as an element can be used more
   than once) to end of the array -
      1. If the current element is smaller than _target_, add it to solution and
        recurse.
      2. Once the function call (recursion) is completed, pop the current element
         and thus backtrack. 

### Implementation

```cpp
void findSolution(vector<int>& nums, vector<int>& currentSolution, vector<vector<int>> &ans, int idx, int target) {
    if (target == 0) {
        ans.push_back(currentSolution);
    } else {
        for (int i = idx; i < (int)nums.size(); i++) {
            int cur = nums[i];
            if (target >= cur) {
                // consider the current number
                currentSolution.push_back(cur);
                findSolution(nums, currentSolution, ans, i, target - cur);
                currentSolution.pop_back(); // backtrack
            }
        }
    }

}

vector<vector<int>> combinationSum(vector<int>& nums, int target) {
    vector<vector<int>> ans;
    vector<int> currentSolution;
    findSolution(nums, currentSolution, ans, 0, target);
    return ans;
}
```

### Complexity Analysis

- **Time Complexity**: Computation of the exact time complexity is difficult.
   However, we can give an upper bound of ${depth\;of\;recursion\;tree}^{no\;of\; maximum\;branchings} = O(N ^ {\lceil\frac{target}{min(nums)}\rceil})$, where $N$ is the number
   of elements in _nums_.
- **Space Complexity**: $O(N)$ extra for the recursion stack.
