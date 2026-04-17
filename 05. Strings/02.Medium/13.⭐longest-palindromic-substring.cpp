#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int expandAroundCenter(string s, int left, int right)
  {
    while (left >= 0 && right < s.length() && s[left] == s[right])
    {
      left--;
      right++;
    }

    return right - left - 1;
  }
  string longestPalindrome(string s)
  {
    if (s.empty())
    {
      return "";
    }

    int start = 0;
    int end = 0;

    for (int i = 0; i < s.length(); i++)
    {
      int odd = expandAroundCenter(s, i, i);
      int even = expandAroundCenter(s, i, i + 1);

      int max_len = max(odd, even);

      if (max_len > end - start)
      {
        start = i - (max_len - 1) / 2;
        end = i + max_len / 2;
      }
    }

    return s.substr(start, end - start + 1);
  }
};

/*
Time complexity: O(n^2)
"n" is the length of the input string "s." This is because the code uses nested loops. The outer loop runs for each character in the string, and the inner loop, expand_around_center, can potentially run for the entire length of the string in the worst case, leading to a quadratic time complexity.

Space complexity: O(1)
the code uses a constant amount of extra space for variables like "start," "end," "left," "right," and function parameters. The space used does not depend on the size of the input string.
*/

// Link: https://leetcode.com/problems/longest-palindromic-substring/