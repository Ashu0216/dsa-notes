#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool checkOnesSegment(string s)
  {

    int count = 0;

    for (int i = 0; i < s.length(); i++)
    {
      if (s[i] == '1' && (i == 0 || s[i - 1] == '0'))
      {
        count++;
      }
    }

    return count <= 1;
  }
};

// Link: https://leetcode.com/problems/check-if-binary-string-has-at-most-one-segment-of-ones/description

/*
Given a binary string s ​​​​​without leading zeros, return true​​​ if s contains at most one contiguous segment of ones. Otherwise, return false.

Example 1:
Input: s = "1001"
Output: false
Explanation: The ones do not form a contiguous segment.

Example 2:
Input: s = "110"
Output: true
*/