#include <iostream>
#include <vector>
using namespace std;

// Dutch National Flag Algorithm

/*
The problem is similar to "Segregate 0s and 1s in an array". The idea is to sort the array of size n using three pointers: low = 0, mid = 0 and high = n - 1 such that the array is divided into 4 parts -

arr[0 .. low - 1] → All 0s
arr[low .. mid - 1] → All 1s
arr[mid .. high] → Unprocessed elements (unknown)
arr[high + 1 .. n - 1] → All 2s
Here,

low is the index where the next 0 should be placed,
mid is the current element being checked,
high is the index where the next 2 should be placed.

*/

void sort012(vector<int> &arr) {
    int n = arr.size();
    
    // initialize three pointers:
    // lo: boundary for 0s
    // mid: current element being checked
    // hi: boundary for 2s
    int lo = 0;
    int hi = n - 1;
    int mid = 0;
    
    // process elements until mid crosses hi
    while (mid <= hi) {
        if (arr[mid] == 0) {
            
            // current is 0: swap with lo and move both 
            // pointers forward
            swap(arr[lo++], arr[mid++]);
        }
        else if (arr[mid] == 1) {
            // current is 1: it's already in correct position
            mid++;
        }
        else {
            // current is 2: swap with hi and move hi backward
            // do not increment mid, as swapped value needs
            // to be re-checked
            swap(arr[mid], arr[hi--]);
        }
    }
}

/*
╭──────────────────────────────────────────────────────────────╮
│                        Complexity                            │
├──────────────────────────────────────────────────────────────┤
│  Time  : O(N)                                                │
│  Space : O(1)                                                │
│--------------------------------------------------------------│
│  Notes : Single pass using three pointers                    │
│          In-place swaps (no extra array used)                │
│          Based on Dutch National Flag approach               │
╰──────────────────────────────────────────────────────────────╯
*/

// Link: https://leetcode.com/problems/sort-colors/description/
