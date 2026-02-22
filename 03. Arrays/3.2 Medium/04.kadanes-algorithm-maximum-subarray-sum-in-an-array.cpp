#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int maxSubArray(vector<int> &nums)
  {

    long long maxi = LLONG_MIN;

    // current sum of subarray
    long long sum = 0;

    for (int i = 0; i < nums.size(); i++)
    {

      // Add current element to the sum
      sum += nums[i];

      // Update maxi if current sum is greater
      if (sum > maxi)
      {
        maxi = sum;
      }

      // Reset sum to 0 if it becomes negative
      if (sum < 0)
      {
        sum = 0;
      }
    }

    return maxi;
  }
};

/*
╭──────────────────────────────────────────────────────────────╮
│              Complexity                                      │
├──────────────────────────────────────────────────────────────┤
│  Time  : O(N)                                                │
│  Space : O(1)                                                │
│--------------------------------------------------------------│
│  Notes  : We traverse the entire original array only once    │
│           No extra data structure                            │
╰──────────────────────────────────────────────────────────────╯
*/

// Link: https://leetcode.com/problems/maximum-subarray/description/
