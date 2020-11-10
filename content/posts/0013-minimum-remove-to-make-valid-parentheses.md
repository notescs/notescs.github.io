---
title: Minimum Remove to Make Valid Parentheses
date: "2020-11-07"
template: "post"
draft: false
slug: minimum-remove-to-make-valid-parentheses
category: "Data Structures & Algorithms"
tags:
  - "cpp"
  - "medium"
  - "Stack"
description: "Given a string, remove minimum number of parentheses to make it
balanced."
---

## Problem

Given a string of characters with parentheses '(' and ')', find the minimum of
parentheses required to remove in order to make the string balanced. Return the
balanced string.

A balanced string is such a string where - 
- an opening parenthesis '(' has a corresponding closing parethesis ')' or,
- an empty string.

**Examples**

Input: "abc(d(e)"  
Output: "abcd(e)" or "abc(de)"

Input: "Hello World!"  
Output: "Hello World!"  
Explanation: A string without any parenthesis is also a balanced string.

Input: "))((("  
Output: ""  
Explanation: An empty string is also a balanced string.

## Solution

### Using Stack

For an invalid string there could be three cases at each character:

- It is an extra opening parenthesis
- It is an extra closing parenthesis
- It is a valid character

We can check them using a stack.

- Iterate through the characters -
    - If a character is an opening parenthesis, push the index to the stack
    - If it is a closing parenthesis -
        - Check if the stack is empty, if it is not empty (valid character), pop the last item from the stack
        - Else, this index (closing parenthesis) is invalid, we will mark the position in the string as `#`
- If the stack is not empty, the stack contains the position of the invalid opening parentheses, we will mark those as `#` in the string.
- In the end, remove those `#` marked characters.

```cpp
string minRemoveToMakeValid(string s) {
    stack<int>openingIndex;
    for (int i = 0; i < (int)s.length(); ++i) {
        if (s[i] == '(') {
            openingIndex.push(i);
        } else if (s[i] == ')') {
            if (!openingIndex.empty()) {
                openingIndex.pop();
            } else {
                // extra closing parenthesis
                s[i] = '#';
            }
        }
    }
    // extra opening parentheses
    while(!openingIndex.empty()) {
        s[openingIndex.top()] = '#';
        openingIndex.pop();
    }
    s.erase(remove(s.begin(), s.end(), '#'), s.end());
    return s;
}
```

**Time Complexity:** $O(n)$, where $n$ is the length of the string, as we have to iterate through all the characters.

**Space Complexity**: $O(n)$, where $n$ is the length of the string, for the required stack.

### Using Count Variables to Check Balance

Two variables `openingCount` and `closingCount` are maintained to count the opening and closing parentheses. We can use different conditions to check if a parenthesis is a valid one or not.

```cpp
string minRemoveToMakeValid(string s) {
    int openingCount = 0, cur = 0;
    int closingCount = count(s.begin(), s.end(), ')');
    for (int i = 0; i < (int)s.length(); i++) {
        if (s[i] == '(') {
            // increment openingCount for an upcoming closing parenthesis
            ++openingCount;
            // a closing parenthesis exists, thus this is a valid
            // opening parenthesis
            if (closingCount > 0) {
                --closingCount;
            } else {
                continue;
            }
        } else if (s[i] == ')') {
            // an opening parenthesis exists for a closing parenthesis,
            // thus valid opening parentheis
            if (openingCount > 0) {
                --openingCount;
            } else {
                --closingCount;
                continue;
            }
        }
        // including the valid character to the string
        s[cur] = s[i];
        ++cur;
    }
    // remove everything from cur to the end
    s.erase(cur);
    return s;
}
```

**Time Complexity:** $O(n)$, where $n$ is the length of the string, as we have to iterate through all the characters.

**Space Complexity**: $O(1)$
