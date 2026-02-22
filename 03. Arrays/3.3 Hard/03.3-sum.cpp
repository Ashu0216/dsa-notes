#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool hasTripletSum(vector<int> &arr, int target)
{
  int n = arr.size();
  sort(arr.begin(), arr.end());

  // Fix the first element as arr[i]
  for (int i = 0; i < n - 2; i++)
  {

    // Skip duplicates for first element
    if (i > 0 && arr[i] == arr[i - 1])
      continue;

    // Initialize left and right pointers with
    // start and end of remaining subarray
    int l = i + 1, r = n - 1;

    int requiredSum = target - arr[i];
    while (l < r)
    {
      if (arr[l] + arr[r] == requiredSum)
        return true;
      if (arr[l] + arr[r] < requiredSum)
        l++;
      else if (arr[l] + arr[r] > requiredSum)
        r--;
    }
  }

  return false;
}


/*
╭──────────────────────────────────────────────────────────────╮
│                        Complexity                            │
├──────────────────────────────────────────────────────────────┤
│  Time  : O(N²)                                               │
│          (O(N log N) sorting + O(N²) two-pointer scan)       │
│  Space : O(1)  (excluding output)                            │
│--------------------------------------------------------------│
│  Note  : Fix one element, use two pointers for rest          │
│          Skip duplicates to avoid repeated triplets          │
│          Extra space only for storing result                 │
╰──────────────────────────────────────────────────────────────╯
*/

// Link: https://leetcode.com/problems/3sum/description/
