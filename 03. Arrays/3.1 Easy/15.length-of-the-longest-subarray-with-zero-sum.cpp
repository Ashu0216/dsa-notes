#include <bits/stdc++.h>
using namespace std;

int maxLen(int A[], int n) {
  // map prefix sum -> first index seen
  unordered_map<int, int> mpp;
  
  int maxi = 0;
  int sum = 0;

  for (int i = 0; i < n; i++) {
    sum += A[i];

    // if sum is zero, subarray [0..i] has zero sum
    if (sum == 0) {
      maxi = i + 1;
    }
    else {
      if (mpp.find(sum) != mpp.end()) {   // check if this sum was seen before
        maxi = max(maxi, i - mpp[sum]);   // when seen, zero-sum segment between previous index + 1 and i
      }
      else { 
        mpp[sum] = i;        // first time seeing this sum, record index
      }
    }
  }

  return maxi;
}

/*
╭──────────────────────────────────────────────────────────────╮
│              Complexity                                      │
├──────────────────────────────────────────────────────────────┤
│  Time  : O(N) (average case)                                 │
│  Space : O(N)                                                │
│--------------------------------------------------------------│
│  Notes  : Single traversal of array                          │
│           Unordered map stores prefix sums                   │
│           Map can grow up to N entries in worst case         │
│           Each lookup/insertion is O(1) average              │
╰──────────────────────────────────────────────────────────────╯
*/