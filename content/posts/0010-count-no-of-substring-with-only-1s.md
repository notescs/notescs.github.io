---
title: Count Number of Substrings with Only 1s
date: "2020-07-13"
template: "post"
draft: false
slug: "count-no-of-substring-with-only-1s"
category: "Data Structures & Algorithms"
tags:
  - "cpp"
  - "python"
  - "sliding-window"
  - "easy"
description: "Given a binary string, count no of substrings with only 1's."
---

Given a binary string, count no of substrings with only 1's. Since the resulting
count can be huge, return it modulo $10^9 + 7$.

**Example**:

Input: "11101101"  
Output: 10  
Explanation: "1" occurs 6 times, "11" occurs 3 times and "111" occurs 1 time. Thus
number of substrings with only 1's = 6 + 3 + 1 = 10.

## Approach: Sliding Window

### Intuition

We can see that a '0' divides two blocks of '1's. For a block of '1' with length `l`
has $1 + 2 + 3 + ... + l = l * (l + 1) / 2$ substrings. Thus, we only need to
count the length of each block of 1's and use the above formula.

For example, the string "11101101" can be divided into blocks of 1's having
3 characters, 2 characters and 1 character which will give 3 * (3 + 1) / 2 = 6,
2 * (2 + 1) / 2 = 3 and 1 * (1 + 1) / 2 = 1 substring respectively.

### Implementation

C++ code:

```cpp
#include <iostream>
#include <string>
using namespace std;

int subCount(string s) {
    const int MOD = 1e9 + 7;
    int i = 0, l = s.length();
    int ans = 0;
    while (i < l) {
        int count = 0;  // count gives length of block of 1's
        if (s[i] == '1') {
            while(i < l and s[i] == '1') {
                ++count;
                ++i;
            }
            long substringCount = 1L * count * (count + 1) / 2 % MOD;
            ans = (ans + substringCount) % MOD;
        } else {
            ++i;
        }
    }
    return ans;
}

int main() {
    cout << "Number of substring with only 1's for 11101101 is " << subCount("11101101") << endl;
    return 0;
}
```

Python code:

```python
def sub_count(s):
    MOD = 10**9 + 7
    i = 0
    l = len(s)
    ans = 0
    while i < l:
        if s[i] == '1':
            count = 0  # count gives length of block of 1's
            while i < l and s[i] == '1':
                count += 1
                i += 1
            substring_count = count * (count + 1) // 2 % MOD
            ans = (ans + substring_count) % MOD
        else:
            i += 1
    return ans

if __name__ == '__main__':
    print("Number of substring with only 1's for 11101101 is", sub_count('11101101'))
```

### Complexity Analysis

- **Time Complexity**: $O(n)$ where $n$ is the length of string.
- **Space Complexity**: $O(1)$ as we are not using any extra space.
