#include <iostream>
using namespace std;

/* Function to sort array using insertion sort */
void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        /* Move elements of arr[0..i-1], that are
           greater than key, to one position ahead
           of their current position */
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

/*
╭──────────────────────────────────────────────────────────────╮
│                         Complexity                           │
├──────────────────────────────────────────────────────────────┤
│  Best   : O(N)                                               │
│  Average: O(N^2)                                             │
│  Worst  : O(N^2)                                             │
│  Space  : O(1)                                               │
│--------------------------------------------------------------│
│  Notes  : Stable sorting algorithm                           │
│           In-place                                           │
│           Efficient for nearly sorted arrays                 │
╰──────────────────────────────────────────────────────────────╯
*/

/*
Insertion sort is a simple sorting algorithm that works by iteratively inserting each element of an unsorted list into its correct position in a sorted portion of the list. It is like sorting playing cards in your hands. You split the cards into two groups: the sorted cards and the unsorted cards. Then, you pick a card from the unsorted group and put it in the right place in the sorted group.

1. Start with the second element as the first element is assumed to be sorted.

2. Compare the second element with the first if the second is smaller then swap them.

3. Move to the third element, compare it with the first two, and put it in its correct position
Repeat until the entire array is sorted.

https://www.geeksforgeeks.org/dsa/insertion-sort-algorithm/
*/