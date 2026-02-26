#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int lowerBound(vector<int> &nums, int target)
  {
    int high = nums.size() - 1;
    int low = 0;
    int mid = low + (high - low) / 2;
    int lb = nums.size();

    while (low <= high)
    {
      if (nums[mid] >= target)
      {
        lb = mid;
        high = mid - 1;
      }
      else
        low = mid + 1;
      mid = low + (high - low) / 2;
    }

    return lb;
  }

  int upperBound(vector<int> &nums, int target)
  {
    int high = nums.size() - 1;
    int low = 0;
    int mid = low + (high - low) / 2;
    int lb = nums.size();

    while (low <= high)
    {
      if (nums[mid] > target)
      {
        lb = mid;
        high = mid - 1;
      }
      else
        low = mid + 1;
      mid = low + (high - low) / 2;
    }

    return lb;
  }

  vector<int> searchRange(vector<int> &nums, int target)
  {

    int lb = lowerBound(nums, target);

    if (lb == nums.size() || nums[lb] != target)
    {
      return {-1, -1};
    }

    return {lb, upperBound(nums, target) - 1};
  }

};

// Link : https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
