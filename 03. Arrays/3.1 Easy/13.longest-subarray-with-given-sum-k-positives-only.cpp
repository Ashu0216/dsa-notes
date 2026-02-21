#include <bits/stdc++.h>
using namespace std;

// Approach: Using Prefix Sum and Hash Map

int getLongestSubarray(vector<int> &nums, int k)
{
  // Write your code here

  int sum = 0;
  map<long long, int> prefixSum;
  int n = nums.size();
  int maxLen = 0;

  for (int i = 0; i < n; i++)
  {
    // calculate sum
    sum += nums[i];

    // if sum == k, get maxLen

    if (sum == k)
    {
      maxLen = max(maxLen, i + 1);
    }

    // check for remaining x-k in prefixSum

    long long rem = sum - k;

    if (prefixSum.find(rem) != prefixSum.end())
    {
      maxLen = max(maxLen, i - prefixSum[rem]);
    }

    // update the map
    if (prefixSum.find(sum) == prefixSum.end())
    {
      prefixSum[sum] = i;
    }
  }

  return maxLen;
}

/*
╭──────────────────────────────────────────────────────────────╮
│              Complexity                                      │
├──────────────────────────────────────────────────────────────┤
│  Time  : O(N log N)                                          │
│  Space : O(N)                                                │
│--------------------------------------------------------------│
│  Notes  : Single traversal of array                          │
│           Each map operation takes O(log N) time             │
│           Map stores at most N prefix sums                   │
╰──────────────────────────────────────────────────────────────╯
*/

// Approach 2: Using Sliding Window

int longestSubarray(vector<int> &nums, int k)
{
  int n = nums.size();

  // To store the maximum length of the subarray
  int maxLen = 0;

  // Pointers to mark the start and end of window
  int left = 0, right = 0;

  // To store the sum of elements in the window
  int sum = nums[0];

  while (right < n)
  {

    // If the sum exceeds K, shrink the window
    while (left <= right && sum > k)
    {
      sum -= nums[left];
      left++;
    }

    // store the maximum length
    if (sum == k)
    {
      maxLen = max(maxLen, right - left + 1);
    }

    right++;
    if (right < n)
      sum += nums[right];
  }

  return maxLen;
}

/*
╭──────────────────────────────────────────────────────────────╮
│              Complexity                                      │
├──────────────────────────────────────────────────────────────┤
│  Time  : O(N)                                                │
│  Space : O(1)                                                │
│--------------------------------------------------------------│
│  Notes  : Two-pointer sliding window                         │
│           Each element processed at most once                │
╰──────────────────────────────────────────────────────────────╯
*/

// Link: https://www.naukri.com/code360/problems/longest-subarray-with-sum-k_5713505?leftPanelTabValue=SUBMISSION