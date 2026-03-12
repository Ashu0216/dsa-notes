#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  long int hours(vector<int> &piles, int k)
  {
    long int count = 0;
    for (int i = 0; i < piles.size(); i++)
    {
      count += ceil((double)piles[i] / (double)k);
      // count += (piles[i] + k - 1) / k;
      // This is a common trick to calculate the ceiling of an integer division without using floating-point arithmetic. It works by adding (k - 1) to the numerator before performing the integer division. This way, if there is any remainder when dividing piles[i] by k, it will effectively round up to the next integer. this is for avaiding the runtime error of overlow
    }
    return count;
  }
  int findMax(vector<int> &piles)
  {
    int max = INT_MIN;
    for (int i = 0; i < piles.size(); i++)
    {
      if (piles[i] > max)
        max = piles[i];
    }
    return max;
  }
  int minEatingSpeed(vector<int> &piles, int h)
  {

    if (h < piles.size())
      return -1;

    int low = 1;
    int high = findMax(piles);

    while (low <= high)
    {
      long int mid = low + (high - low) / 2;

      long int ans = hours(piles, mid);

      if (ans > h)
        low = mid + 1;
      else
        high = mid - 1;
    }

    return low;
  }
};

// Time Complexity: O(N*log(max(a[]))), we apply binary search on our search space to reduce it into half at every step.

// Link: https://leetcode.com/problems/koko-eating-bananas/submissions/1651899133/