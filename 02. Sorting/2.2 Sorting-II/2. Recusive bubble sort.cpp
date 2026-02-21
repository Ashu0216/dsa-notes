#include <bits/stdc++.h>
using namespace std;

// A function to implement bubble sort
void bubbleSort(int arr[], int n)
{
  // Base case
  if (n == 1)
    return;

  int count = 0;
  // One pass of bubble sort. After
  // this pass, the largest element
  // is moved (or bubbled) to end.
  for (int i = 0; i < n - 1; i++)
    if (arr[i] > arr[i + 1])
    {
      swap(arr[i], arr[i + 1]);
      count++;
    }

  // check if any swapping occur or not
  if (count == 0)
    return;

  // Largest element is fixed,
  // recur for remaining array
  bubbleSort(arr, n - 1);
}

/*
1. Base Case: If array size is 1, return.
2. Do One Pass of normal Bubble Sort. This pass fixes last element of current subarray.
3. Recur for all elements except last of current subarray.
*/