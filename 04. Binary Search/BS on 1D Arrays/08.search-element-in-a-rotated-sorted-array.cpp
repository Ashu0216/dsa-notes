#include <iostream>
#include <vector>
using namespace std;

// Approach 1: Using Binary Search Twice - O(log n) Time and O(1) Space

// The main Idea is to first finds the index of the smallest element (pivot), which is also the number of rotations applied to the sorted array. Once the pivot is known, the array is split into two sorted subarrays.

// An iterative binary search function
int binarySearch(vector<int> &arr, int lo, int hi, int x)
{
  while (lo <= hi)
  {
    int mid = lo + (hi - lo) / 2;
    if (arr[mid] == x)
      return mid;
    if (arr[mid] < x)
      lo = mid + 1;
    else
      hi = mid - 1;
  }
  return -1;
}

// Function to return pivot (index of the smallest element)
int findPivot(vector<int> &arr, int lo, int hi)
{
  while (lo <= hi)
  {

    // The current subarray is already sorted,
    // the minimum is at the low index
    if (arr[lo] <= arr[hi])
      return lo;

    int mid = (lo + hi) / 2;

    // The right half is not sorted. So the minimum element must be in the right half.
    if (arr[mid] > arr[hi])
      lo = mid + 1;

    // The right half is sorted. Note that in this case, we do not change high to mid - 1 but keep it to mid. The mid element itself can be the smallest
    else
      hi = mid;
  }

  return lo;
}

int search(vector<int> &arr, int key)
{
  int n = arr.size();
  int pivot = findPivot(arr, 0, n - 1);

  // If we found a pivot, then first compare with pivot
  // and then search in two subarrays around pivot
  if (arr[pivot] == key)
    return pivot;

  // If the minimum element is present at index
  // 0, then the whole array is sorted
  if (pivot == 0)
    return binarySearch(arr, 0, n - 1, key);

  if (arr[0] <= key)
    return binarySearch(arr, 0, pivot - 1, key);

  return binarySearch(arr, pivot + 1, n - 1, key);
}

// Approach 2 : Using Single Binary Search - O(log n) Time and O(1) Space

// This approach applies a modified version of binary search directly to the entire rotated array. At every iteration, the middle element is checked against the key. If it’s not the key, we determine whether the left half or right half is sorted by comparing values at arr[lo] and arr[mid]. If the left half is sorted and the key lies within its range, we adjust hi = mid - 1; otherwise, we shift lo = mid + 1. If the right half is sorted and the key lies within its range, we move lo = mid + 1; else, hi = mid - 1.

class Solution
{
public:
  int search(vector<int> &nums, int target)
  {
    int low = 0;
    int high = nums.size() - 1;
    int mid = low + (high - low) / 2;

    while (low <= high)
    {

      if (nums[mid] == target)
        return mid;

      if (nums[low] <= nums[mid])
      {
        if (nums[low] <= target && target <= nums[mid])
        {
          high = mid - 1;
        }
        else
          low = mid + 1;
      }

      else if (nums[mid] <= nums[high])
      {
        if (nums[mid] <= target && target <= nums[high])
        {
          low = mid + 1;
        }
        else
          high = mid - 1;
      }

      mid = low + (high - low) / 2;
    }

    return -1;
  }
};

// Time Complexity: O(log N),We eliminate half of the search space in each iteration using binary search.

// Link: https://leetcode.com/problems/search-in-rotated-sorted-array/
