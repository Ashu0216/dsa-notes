#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int numberOfDays(vector<int> &weights, int mid)
  {
    int days = 0;
    int sum = 0;

    for (int i = 0; i < weights.size(); i++)
    {
      if (sum + weights[i] <= mid)
      {
        sum += weights[i];
      }
      else
      {
        days++;
        sum = weights[i];
      }
    }

    if (sum > 0)
      days++;

    return days;
  }
  int shipWithinDays(vector<int> &weights, int days)
  {

    int low = *max_element(weights.begin(), weights.end());
    int high = 0;
    for (int i = 0; i < weights.size(); i++)
      high += weights[i];

    while (low <= high)
    {
      int mid = (low + high) / 2;

      int dayreq = numberOfDays(weights, mid);

      // cout << "mid: " << mid << " days: " << dayreq << endl;

      if (dayreq <= days)
      {
        high = mid - 1;
      }
      else
      {
        low = mid + 1;
      }
    }

    return low;
  }
};

// Time Complexity: O(N * log(S)), where N is number of packages and S is the search space (sum_weights - max_weight). Each binary search step takes O(N), repeated O(log S) times.

// Link: https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/