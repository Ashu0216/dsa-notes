#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int numBouqets(vector<int> &bloomDay, int mid, int k)
  {
    int count = 0;
    int bouq = 0;

    for (int i = 0; i < bloomDay.size(); i++)
    {
      if (bloomDay[i] <= mid)
      {
        count++;
        if (count == k)
        {
          bouq += 1;
          count = 0;
        }
      }
      else
        count = 0;
    }

    return bouq;
  }
  int minDays(vector<int> &bloomDay, int m, int k)
  {

    // Important condition
    if ((long int)k * m > bloomDay.size())
      return -1;

    int low = *min_element(bloomDay.begin(), bloomDay.end());
    int high = *max_element(bloomDay.begin(), bloomDay.end());

    while (low <= high)
    {
      int mid = low + (high - low) / 2;

      int bouq = numBouqets(bloomDay, mid, k);

      if (bouq < m)
        low = mid + 1;
      else
        high = mid - 1;
    }

    return low;
  }
};

// Time Complexity: O(1) O(log(max(arr[])-min(arr[])+1) * N), where {max(arr[]) -> maximum element of the array, min(arr[]) -> minimum element of the array, N = size of the array}.

// Link: https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/submissions/1651927378/