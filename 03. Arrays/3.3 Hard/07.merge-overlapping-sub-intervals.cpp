#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {

    // Sort intervals based on start values
    sort(arr.begin(), arr.end());
  
    vector<vector<int>> res;
    res.push_back(arr[0]);

    for (int i = 1; i < arr.size(); i++) {
        vector<int>& last = res.back();
        vector<int>& curr = arr[i];

        // If current interval overlaps with the last merged
        // interval, merge them 
        if (curr[0] <= last[1]) 
            last[1] = max(last[1], curr[1]);
        else 
            res.push_back(curr);
    }

    return res;
}

/*
╭──────────────────────────────────────────────────────────────╮
│                       Algorithm                              │
├──────────────────────────────────────────────────────────────┤
│  1. Sort intervals by starting time                          │
│  2. Add first interval to result                             │
│  3. For each next interval:                                  │
│       - If it overlaps with last merged interval             │
│         → merge by updating end time                         │
│       - Else → push it as a new interval                     │
│                                                              │
│  Idea : After sorting, only compare with last merged         │
│         interval (no need to check all previous ones)        │
╰──────────────────────────────────────────────────────────────╯
*/

/*
╭──────────────────────────────────────────────────────────────╮
│                        Complexity                            │
├──────────────────────────────────────────────────────────────┤
│  Time  : O(N log N)                                          │
│          (Sorting dominates, merging is linear)              │
│  Space : O(N)                                                │
│--------------------------------------------------------------│
│  Note  : Extra space used for storing merged intervals       │
│          Only single linear traversal after sorting          │
╰──────────────────────────────────────────────────────────────╯
*/

// Link: https://leetcode.com/problems/merge-intervals/description/