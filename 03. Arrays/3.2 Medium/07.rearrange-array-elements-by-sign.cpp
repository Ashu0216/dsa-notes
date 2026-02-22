#include <bits/stdc++.h>
using namespace std;

class ArrayManipulator
{
public:
  vector<int> rearrangeArray(vector<int> &nums)
  {

    vector<int> ans(nums.size(), 0);

    int pos = 0;
    int neg = 1;

    for (int i = 0; i < nums.size(); i++)
    {
      if (nums[i] > 0)
      {
        ans[pos] = nums[i];
        pos += 2;
      }

      else if (nums[i] < 0)
      {
        ans[neg] = nums[i];
        neg += 2;
      }
    }

    return ans;
  }
};

/*
╭──────────────────────────────────────────────────────────────╮
│                        Complexity                            │
├──────────────────────────────────────────────────────────────┤
│  Time  : O(N)                                                │
│  Space : O(N)                                                │
│--------------------------------------------------------------│
│  Note  : Single traversal                                    │
│          Extra array used for alternating placement          │
╰──────────────────────────────────────────────────────────────╯
*/

// Link: https://leetcode.com/problems/rearrange-array-elements-by-sign/description/
