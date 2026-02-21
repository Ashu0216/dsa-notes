// Recursive C++ program for insertion sort
#include <iostream>
using namespace std;

// Recursive function to sort an array using
// insertion sort
void insertionSortRecursive(int arr[], int n)
{
    // Base case
    if (n <= 1)
        return;

    // Sort first n-1 elements
    insertionSortRecursive( arr, n-1 );

    // Insert last element at its correct position
    // in sorted array.
    int last = arr[n-1];
    int j = n-2;

    /* Move elements of arr[0..i-1], that are
    greater than key, to one position ahead
    of their current position */
    while (j >= 0 && arr[j] > last)
    {
        arr[j+1] = arr[j];
        j--;
    }
    arr[j+1] = last;
}

/*
╭──────────────────────────────────────────────────────────────╮
│                         Complexity                           │
├──────────────────────────────────────────────────────────────┤
│  Best   : O(N)                                               │
│  Average: O(N^2)                                             │
│  Worst  : O(N^2)                                             │
│  Space  : O(N)                                               │
│--------------------------------------------------------------│
│  Notes  : Stable sorting algorithm                           │
│           Recursive implementation                           │
│           O(N) stack space due to recursion                  │
╰──────────────────────────────────────────────────────────────╯
*/

/*
Base Case: If array size is 1 or smaller, return.
Recursively sort first n-1 elements.
Insert last element at its correct position in sorted array.
*/