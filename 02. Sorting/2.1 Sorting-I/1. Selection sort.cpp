#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int> &arr) {
    int n = arr.size();

    for (int i = 0; i < n - 1; ++i) {

        // Assume the current position holds
        // the minimum element
        int min_idx = i;

        // Iterate through the unsorted portion
        // to find the actual minimum
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[min_idx]) {

                // Update min_idx if a smaller
                // element is found
                min_idx = j; 
            }
        }

        // Move minimum element to its
        // correct position
        swap(arr[i], arr[min_idx]);
    }
}

/*
╭──────────────────────────────────────────────────────────────╮
│                         Complexity                           │
├──────────────────────────────────────────────────────────────┤
│  Time  : O(N^2)                                              │
│  Space : O(1)                                                │
│--------------------------------------------------------------│
│  Notes : Always performs N(N-1)/2 comparisons                │
│          Not stable by default                               │
╰──────────────────────────────────────────────────────────────╯
*/

/*
Selection Sort is a comparison-based sorting algorithm. It sorts by repeatedly selecting the smallest (or largest) element from the unsorted portion and swapping it with the first unsorted element.

1. Find the smallest element and swap it with the first element. This way we get the smallest element at its correct position.

2. Then find the smallest among remaining elements (or second smallest) and swap it with the second element.

3. We keep doing this until we get all elements moved to correct position.

https://www.geeksforgeeks.org/dsa/selection-sort-algorithm-2/
*/
