#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> fourSum(vector<int>& arr, int target) {
    vector<vector<int>> res;
    int n = arr.size();

    // Sort the array
    sort(arr.begin(), arr.end());

    // Generate quadruplets
    for (int i = 0; i < n; i++) {
      
        // Skip duplicates for i
        if (i > 0 && arr[i] == arr[i - 1]) continue;

        for (int j = i + 1; j < n; j++) {
            
            // Skip duplicates for j
            if (j > i + 1 && arr[j] == arr[j - 1]) continue;

            int k = j + 1, l = n - 1;

            // Two pointers approach
            while (k < l) {
                int sum = arr[i] + arr[j] + arr[k] + arr[l];
                if (sum == target) {
                    res.push_back({arr[i], arr[j], arr[k], arr[l]});
                    k++;
                    l--;

                    // Skip duplicates for k and l
                    while (k < l && arr[k] == arr[k - 1]) k++;
                    while (k < l && arr[l] == arr[l + 1]) l--;
                } else if (sum < target) {
                    k++;
                } else {
                    l--;
                }
            }
        }
    }
    return res;
}

/*
╭──────────────────────────────────────────────────────────────╮
│                        Complexity                            │
├──────────────────────────────────────────────────────────────┤
│  Time  : O(N³)                                               │
│          (O(N log N) sorting + O(N³) traversal)              │
│  Space : O(1)  (excluding output)                            │
│--------------------------------------------------------------│
│  Note  : Fix two elements, apply two-pointer on rest         │
│          Skip duplicates to avoid repeated quadruplets       │
│          Extra space only used for storing result            │
╰──────────────────────────────────────────────────────────────╯
*/

// Link: https://leetcode.com/problems/4sum/description/