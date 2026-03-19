#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int countSubArrays(vector<int> &nums, int target)
  {
    int currSum = nums[0];
    int count = 1;

    for (int i = 1; i < nums.size(); i++)
    {
      if (currSum + nums[i] <= target)
      {
        currSum += nums[i];
      }
      else
      {
        currSum = nums[i];
        count++;
      }
    }
    return count;
  }
  int splitArray(vector<int> &nums, int k)
  {

    // k subarray
    // sum of array minimized

    int low = *max_element(nums.begin(), nums.end());
    int high = 0;
    for (int i = 0; i < nums.size(); i++)
    {
      high += nums[i];
    }

    if (k == 1)
      return high;

    while (low <= high)
    {
      int mid = (low + high) / 2;

      int count = countSubArrays(nums, mid);

      if (count > k)
      {
        low = mid + 1;
      }
      else
      {
        high = mid - 1;
      }
    }

    return low;
  }
};

/*
Time Complexity: O(N * log(sum(arr[])-max(arr[])+1)), where N = size of the array, sum(arr[]) = sum of all array elements, max(arr[]) = maximum of all array elements.

Space Complexity: O(1), no extra space used
*/

// Link: https://leetcode.com/problems/split-array-largest-sum/