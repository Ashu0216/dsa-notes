#include <bits/stdc++.h>
using namespace std;

class GasStationOptimizer
{
public:
  // Function to calculate number of gas stations required such that
  // no segment exceeds the max allowed distance `dist`
  int numberOfGasStationsRequired(long double dist, vector<int> &arr)
  {
    int n = arr.size();
    int cnt = 0;

    for (int i = 1; i < n; i++)
    {
      // Number of stations needed between arr[i-1] and arr[i]
      int numberInBetween = (arr[i] - arr[i - 1]) / dist;

      // If perfectly divisible, reduce one to avoid extra placement
      if ((arr[i] - arr[i - 1]) == (dist * numberInBetween))
      {
        numberInBetween--;
      }
      cnt += numberInBetween;
    }
    return cnt;
  }

  // Function to minimize the maximum distance between gas stations
  long double minimiseMaxDistance(vector<int> &arr, int k)
  {
    int n = arr.size();
    long double low = 0, high = 0;

    // Determine max initial distance between stations
    for (int i = 0; i < n - 1; i++)
    {
      high = max(high, (long double)(arr[i + 1] - arr[i]));
    }

    long double diff = 1e-6;

    // Binary search to find minimum possible maximum distance
    while (high - low > diff)
    {
      long double mid = (low + high) / 2.0;
      int cnt = numberOfGasStationsRequired(mid, arr);
      if (cnt > k)
        low = mid;
      else
        high = mid;
    }

    return high;
  }
};

/* Time Complexity: O(n*log(Len)) + O(n), n = size of the given array, Len = length of the answer space.

Space Complexity: O(1), as we are using no extra space to solve this problem.
*/

// Link: https://www.geeksforgeeks.org/problems/minimize-max-distance-to-gas-station/1
