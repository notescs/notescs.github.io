---
title: Maximum Product of Word Lengths
date: "2021-05-27"
template: "post"
category: "Data Structures & Algorithms"
tags:
  - "cpp"
  - "python"
  - "Difficulty: Medium"
  - "Bit Manipulation"
description: "Given an array of strings, return the maximum value of the product
of lengths where two words do not share any common letters."
---

<!-- Problem Statement -->

Given an array of strings `words`, return the maximum value of the product of lengths
where two words do not share any common letters. The strings only contain lowercase
letters.

_Example 1_

**Input**:  words = ["a", "bcd", "foo", "ba"]  
**Output**:  9  
**Explanation**: Maximum possible product of length of words which do not share
any common letter = length("bcd") * length("foo") = 9

_Example 2_

**Input**: ["a","ab","abc","d","cd","bcd","abcd"]  
**Output**: 4  
**Explanation**: The two words can be "ab", "cd".

## Approach 1: Bit Manipulation

This problem can be solved using bitmasking. Since the number of characters are
limited to only 26, datatype of `int` can be used for masking.

### Intuition

Let us consider only 4 characters in our alphabet: a, b, c and d. We set all the unique
characters' bit from left. Note how the masking is done in the following example:

Word | d | c | b | a | Masked Value (in binary) |
-----|---|---|---|---|--------------------------|
aaaa | 0 | 0 | 0 | 1 | 0001 |
abcaa| 0 | 1 | 1 | 1 | 0111 |
abcd | 1 | 1 | 1 | 1 | 1111 |
bbbc | 0 | 1 | 1 | 0 | 0110 |

Now, if we perform `AND (&)` operation and obtain 0, the words do not share common
characters (see the example of "aaaa" and "bbbc" above).

### Implementation

In C++:

```cpp
int maxProduct(vector<string>& words) {
    vector<int> masks(words.size());
    for (int i = 0; i < (int)words.size(); ++i) {
        for (char c: words[i]) {
            // set the (c - 'a')-th bit from left
            masks[i] |= 1 << (c - 'a');
        }
    }
    int ans = 0;
    for (int i = 0; i < (int)words.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            // If `AND` between two masks is zero, that means
            // they do not share common characters
            if ((masks[i] & masks[j]) == 0) {
                ans = max(ans, (int)words[i].length() * (int)words[j].length());
            }
        }
    }
    return ans;
}
```

> **Implementation note**: If the number of unique characters were more, we could
> have used [`bitset`](http://www.cplusplus.com/reference/bitset/bitset/).

### Complexity Analysis

- **Time Complexity**: $O(N ^ 2 + N * M)$ where $N = $ number of words and $M = $
  average length of the words
- **Space Complexity**: $O(N)$ required for storing the masks


## Approach 2: Bit Manipulation with Pruning

### Intuition

We can improve the performance by sorting the words in descending length order.
This will guarantee that we will get the larger strings first. We can further
improve the performance by lazily computing the masks. Though it doesn't change
the time complexity, it should run faster than the previous implementation.

### Implementation

```cpp
int maxProduct(vector<string>& words) {
    sort(words.begin(), words.end(), [](const string &u, const string &v){
        return u.length() > v.length();
    });
    int ans = 0;
    vector<int> masks(words.size());
    for (int i = 0; i < (int)words.size(); ++i) {
        // prune
        if (ans >= words[i].length() * words[0].length()) return ans;
        // compute mask for the current word only and
        // the store it in the vector
        int &mask = masks[i];
        for (char c: words[i]) {
            // set the (c - 'a')-th bit from left
            mask |= 1 << (c - 'a');
        }
        for (int j = 0; j < i; ++j) {
            if ((mask & masks[j]) == 0) {
                ans = max(ans, (int) words[i].length() * (int)words[j].length());
            }
        }
    }
    return ans;
}
```

### Complexity Analysis

- **Time Complexity**: $O(N ^ 2 + N * M)$ where $N = $ number of words and $M = $
  average length of the words. We don't need to add the sorting time
  complexity $O(NlogN)$, since we have a larger term $N^2$ in the complexity
  expression
- **Space Complexity**: $O(N)$ required for storing the masks
