#include <algorithm>
#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

// [Naive Approach] Using Insert of Insertion Sort

void mergeArrays(vector<int>& a, vector<int>& b) {
  	
  	// Traverse b[] starting from the last element
    for (int i = b.size() - 1; i >= 0; i--) {
      	
        // If b[i] is smaller than the largest element of a[]
        if (a.back() > b[i]) {
          
          	// Place b[i] in the correct position in a[], 
            // and move last element of a[] to b[]
            int last = a.back();
          	int j = a.size() - 2;
            while (j >= 0 && a[j] > b[i]) {
                a[j + 1] = a[j];
                j--;
            }
          
            a[j + 1] = b[i];
            b[i] = last;
        }
    }
}

/*
╭──────────────────────────────────────────────────────────────╮
│                       Algorithm                              │
├──────────────────────────────────────────────────────────────┤
│  1. Traverse array B from end to start                       │
│  2. Compare B[i] with last element of A                      │
│  3. If B[i] < last of A:                                     │
│       - Swap B[i] with last element of A                     │
│       - Insert swapped element in A using insertion step     │
│  4. Continue until all elements of B are processed           │
│                                                              │
│  Idea : Maintain A sorted via insertion step                 │
│         B remains sorted due to reverse traversal            │
│         No extra space used                                  │
╰──────────────────────────────────────────────────────────────╯
*/

/*
╭──────────────────────────────────────────────────────────────╮
│                        Complexity                            │
├──────────────────────────────────────────────────────────────┤
│  Time  : O(M × N)                                            │
│  Space : O(1)                                                │
│--------------------------------------------------------------│
│  Note  : Each insertion in A may take O(N) time              │
│          No auxiliary array used                             │
╰──────────────────────────────────────────────────────────────╯
*/

// [Better Approach 1] Using n-th smallest element

// Find m-th smallest element
// Do a binary search in a[] to find the right index idx
// in a[] such that all combined elements in a[idx..m-1]
// and b[m-idx...n-1] are greater than or equal to all
// the remaining elements (a[0..idx-1] and b[m-idx-1..n-1])
// in both the arrays.
int kthSmallest(vector<int> &a, vector<int> &b, int k) {
    int n = a.size(), m = b.size();
    int lo = 0, hi = n, idx = 0;
    while (lo <= hi) {
        int mid1 = (lo + hi) / 2;
        int mid2 = k - mid1;
       
        // We don't have mid2 elements in b[], so pick more
        // elements from a[]
        if (mid2 > m) {
            lo = mid1 + 1;
            continue;
        }

        // Find elements to the left and right of partition in a[]
        int l1 = (mid1 == 0 ? INT_MIN : a[mid1 - 1]);
        int r1 = (mid1 == n ? INT_MAX : a[mid1]);

        // Find elements to the left and right of partition in b[]
        int l2 = (mid2 == 0 ? INT_MIN : b[mid2 - 1]);
        int r2 = (mid2 == m ? INT_MAX : b[mid2]);

        // If it is a valid partition
        if (l1 <= r2 && l2 <= r1) {
            idx = mid1;
            break;
        }

        // Check if we need to take lesser elements from a[]
        if (l1 > r2)
            hi = mid1 - 1;

        // Check if we need to take more elements from a[]
        else
            lo = mid1 + 1;
    }
    return idx;
}

void mergeArrays(vector<int> &a, vector<int> &b) {
    int n = a.size();
    int m = b.size();
    int idx = kthSmallest(a, b, n);

    // Move all smaller elements in a[]
    for (int i = idx; i < n; i++) {
        swap(a[i], b[i - idx]);
    }

    // Sort both a[] and b[]
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
}

/*
╭──────────────────────────────────────────────────────────────╮
│                       Algorithm                              │
├──────────────────────────────────────────────────────────────┤
│  1. Treat combined arrays as one sorted structure            │
│  2. Conceptually find the nth smallest element (pivot)       │
│  3. Find first index in A where elements > pivot             │
│  4. Swap larger elements of A with smaller elements of B     │
│  5. Finally, sort both A and B individually                  │
│                                                              │
│  Idea : Pivot divides elements correctly between arrays      │
│         Final sorting restores internal order                │
╰──────────────────────────────────────────────────────────────╯
*/

/*
╭──────────────────────────────────────────────────────────────╮
│                        Complexity                            │
├──────────────────────────────────────────────────────────────┤
│  Time  : O(log M + M log M + N log N)                        │
│  Space : O(1)                                                │
│--------------------------------------------------------------│
│  Note  : Binary search for partition index                   │
│          Individual sorting dominates runtime                │
│          No extra array used                                 │
╰──────────────────────────────────────────────────────────────╯
*/

// [Better Approach 2] By Swap and Sort

void mergeArrays(vector<int>& a, vector<int>& b) {
    int i = a.size() - 1, j = 0;

  	// swap smaller elements from b[] 
  	// with larger elements from a[]
    while (i >= 0 && j < b.size() && a[i] > b[j]) {
      	swap(a[i--], b[j++]);
    }

    // Sort both arrays
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
}

/*
╭──────────────────────────────────────────────────────────────╮
│                        Complexity                            │
├──────────────────────────────────────────────────────────────┤
│  Time  : O((M + N) + M log M + N log N)                      │
│  Space : O(1)                                                │
│--------------------------------------------------------------│
│  Note  : Linear swaps before final sorting                   │
│          Sorting step dominates overall time                 │
│          No extra array used                                 │
╰──────────────────────────────────────────────────────────────╯
*/

// [Better Approach 2] Using Gap method

void mergeArrays(vector<int>& a, vector<int>& b) {
    int n = a.size();
    int m = b.size();
    int gap = (n + m + 1) / 2;

    while (gap > 0) {
        int i = 0, j = gap;

        while (j < n + m) {

            // If both pointers are in the first array a[]
            if (j < n && a[i] > a[j]) {
                swap(a[i], a[j]);
            } 
          
            // If first pointer is in a[] and 
            // the second pointer is in b[]
            else if (i < n && j >= n && a[i] > b[j - n]) {
                swap(a[i], b[j - n]);
            } 
          
            // Both pointers are in the second array b
            else if (i >= n && b[i - n] > b[j - n]) {
                swap(b[i - n], b[j - n]);
            }
            i++;
            j++;
        }

        // After operating for gap of 1 break the loop
        if (gap == 1) break;

        // Calculate the next gap
        gap = (gap + 1) / 2;
    }
}

/*
╭──────────────────────────────────────────────────────────────╮
│                       Algorithm                              │
├──────────────────────────────────────────────────────────────┤
│  1. Treat A and B as a single array of size (N + M)          │
│  2. Initialize gap = ceil((N + M) / 2)                       │
│  3. While gap > 0:                                           │
│       - Set left = 0, right = left + gap                     │
│       - Compare elements at left & right positions           │
│         (handle 3 cases: A–A, A–B, B–B)                      │
│       - Swap if left element > right element                 │
│       - Move both pointers forward                           │
│  4. Reduce gap = ceil(gap / 2) until gap = 0                 │
│                                                              │
│  Idea : Shell sort’s gap method without extra space          │
│         Adjust indices when pointer lies in B                │
╰──────────────────────────────────────────────────────────────╯
*/

/*
╭──────────────────────────────────────────────────────────────╮
│                        Complexity                            │
├──────────────────────────────────────────────────────────────┤
│  Time  : O((N + M) log (N + M))                              │
│  Space : O(1)                                                │
│--------------------------------------------------------------│
│  Note  : Gap reduces by half each iteration                  │
│          Each pass performs linear comparison & swaps        │
│          No auxiliary array used                             │
╰──────────────────────────────────────────────────────────────╯
*/

// Link: https://www.naukri.com/code360/problems/merge-two-sorted-arrays-without-extra-space_6898839?&interviewProblemRedirection=true&search=merge%20two%20sorted%20array
