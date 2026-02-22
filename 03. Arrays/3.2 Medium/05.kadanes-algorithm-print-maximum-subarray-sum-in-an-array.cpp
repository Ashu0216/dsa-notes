#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int maxSubArray(vector<int> &nums)
  {

    long long maxi = LLONG_MIN;

    long long sum = 0;

    int start = 0;

    int ansStart = -1, ansEnd = -1;

    for (int i = 0; i < nums.size(); i++)
    {
      if (sum == 0)
      {
        start = i;
      }

      sum += nums[i];

      if (sum > maxi)
      {
        maxi = sum;
        ansStart = start;
        ansEnd = i;
      }

      if (sum < 0)
      {
        sum = 0;
      }
    }

    cout << "The subarray is: [";
    for (int i = ansStart; i <= ansEnd; i++)
    {
      cout << nums[i] << " ";
    }
    cout << "]" << endl;

    return maxi;
  }
};

/*
╭──────────────────────────────────────────────────────────────╮
│                        Complexity                            │
├──────────────────────────────────────────────────────────────┤
│  Time  : O(N)                                                │
│  Space : O(1)                                                │
│--------------------------------------------------------------│
│  Algo  : Kadane’s Algorithm                                  │
│  Note  : Add elements to running sum                         │
│          Reset sum if it becomes negative                    │
│          Track maximum subarray during traversal             │
╰──────────────────────────────────────────────────────────────╯
*/
