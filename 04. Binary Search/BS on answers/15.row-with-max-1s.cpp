#include <bits/stdc++.h>
using namespace std;

// User function template for C++
class Solution
{
public:
  int lowerBound(vector<int> &arr, int n)
  {
    int low = 0, high = n - 1;

    while (low <= high)
    {
      int mid = (low + high) / 2;

      if (arr[mid] == 1)
      {
        high = mid - 1;
      }
      else
      {
        low = mid + 1;
      }
    }

    return high;
  }
  int rowWithMax1s(vector<vector<int>> &arr)
  {
    // code here
    int cnt_max = 0;
    int index = -1;
    int n = arr.size();
    int m = arr[0].size();

    for (int i = 0; i < n; i++)
    {
      int cnt = m - (lowerBound(arr[i], m) + 1);
      // cout << "i :" << i << " , cnt :"<< cnt << endl;
      if (cnt > cnt_max)
      {
        cnt_max = cnt;
        index = i;
      }
    }

    return index;
  }
};

/*
Time Complexity:O(n X logm), where n = given row number, m = given column number. We are using a loop running for n times to traverse the rows. Then we are applying binary search on each row with m columns.

Space Complexity: O(1), no extra space is used.
*/

// Link: https://www.geeksforgeeks.org/problems/row-with-max-1s0023/1