#include <bits/stdc++.h>
using namespace std;

bool placeCows(vector<int> &stalls, int k, int dis)
{
  int count = 1;
  int last = 0;
  for (int i = 1; i < stalls.size(); i++)
  {
    if (stalls[i] - stalls[last] >= dis)
    {
      count++;
      last = i;
    }
  }
  return count >= k;
}

int aggressiveCows(vector<int> &stalls, int k)
{
  sort(stalls.begin(), stalls.end());
  int n = stalls.size();

  int low = 1, high = stalls[n - 1] - stalls[0];

  while (low <= high)
  {
    int mid = (low + high) / 2;

    if (placeCows(stalls, k, mid))
    {
      low = mid + 1;
    }
    else
    {
      high = mid - 1;
    }
  }

  return high;
}
/*
Time Complexity: O(NlogN) + O(N * log(max(stalls[])-min(stalls[]))), where N = size of the array, max(stalls[]) = maximum element in stalls[] array, min(stalls[]) = minimum element in stalls[] array.

Space Complexity: O(1) as we are not using any extra space to solve this problem.
*/

// Link: https://www.naukri.com/code360/problems/aggressive-cows_1082559?interviewProblemRedirection=true&search=aggress&attempt_status=COMPLETED&leftPanelTabValue=PROBLEM&count=25&page=1&sort_entity=order&sort_order=ASC&customSource=studio_nav