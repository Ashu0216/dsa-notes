#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &arr, int low, int high)
{

  // choose the pivot
  int pivot = arr[high];

  // undex of smaller element and indicates
  // the right position of pivot found so far
  int i = low - 1;

  // Traverse arr[low..high] and move all smaller
  // elements on left side. Elements from low to
  // i are smaller after every iteration
  for (int j = low; j <= high - 1; j++)
  {
    if (arr[j] < pivot)
    {
      i++;
      swap(arr[i], arr[j]);
    }
  }

  // move pivot after smaller elements and
  // return its position
  swap(arr[i + 1], arr[high]);
  return i + 1;
}

// the QuickSort function implementation
void quickSort(vector<int> &arr, int low, int high)
{

  if (low < high)
  {

    // pi is the partition return index of pivot
    int pi = partition(arr, low, high);

    // recursion calls for smaller elements
    // and greater or equals elements
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}

int main()
{
  vector<int> arr = {10, 7, 8, 9, 1, 5};
  int n = arr.size();
  quickSort(arr, 0, n - 1);

  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  return 0;
}

/*
╭──────────────────────────────────────────────────────────────╮
│                         Complexity                           │
├──────────────────────────────────────────────────────────────┤
│  Best   : O(N log N)                                         │
│  Average: O(N log N)                                         │
│  Worst  : O(N^2)                                             │
│  Space  : O(log N)  (average recursion stack)                │
│--------------------------------------------------------------│
│  Notes  : Not stable                                         │
│           In-place (no extra array)                          │
│           Worst case when pivot is smallest/largest          │
╰──────────────────────────────────────────────────────────────╯
*/

/*
QuickSort is a sorting algorithm based on the Divide and Conquer that picks an element as a pivot and partitions the given array around the picked pivot by placing the pivot in its correct position in the sorted array. .

There are mainly three steps in the algorithm:

1. Choose a Pivot: Select an element from the array as the pivot. The choice of pivot can vary (e.g., first element, last element, random element, or median).

2. Partition the Array: Re arrange the array around the pivot. After partitioning, all elements smaller than the pivot will be on its left, and all elements greater than the pivot will be on its right.

3. Recursively Call: Recursively apply the same process to the two partitioned sub-arrays.

4. Base Case: The recursion stops when there is only one element left in the sub-array, as a single element is already sorted.

https://www.geeksforgeeks.org/dsa/quick-sort-algorithm/
*/