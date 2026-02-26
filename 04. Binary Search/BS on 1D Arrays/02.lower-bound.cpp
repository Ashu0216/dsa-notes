#include <iostream>
#include <vector>
using namespace std;

// Lower bound : The lower bound of a number is defined as the smallest index in the sorted array where the element is greater than or equal to the target.

// Using Binary Search - O(log n) Time and O(1) Space

int lowerBound(vector<int> &arr, int target)
{
  int low = 0, high = arr.size() - 1;
  int res = arr.size();

  while (low <= high)
  {
    int mid = low + (high - low) / 2;

    if (arr[mid] >= target)
    {
      res = mid;
      high = mid - 1;
    }
    else
    {
      low = mid + 1;
    }
  }
  return res;
}

// Using Built-In Methods - O(log n) Time and O(1) Space

int lowerBound(vector<int> &arr, int target)
{

  // Using inbuilt method
  int index = lower_bound(arr.begin(), arr.end(), target) - arr.begin();

  return index;
}