#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int, int> prefixSumCount;

        int prefixSum = 0;
        int count = 0;

        prefixSumCount[0] = 1;

        for (int i = 0; i < n; i++) {
            // Add current element to prefix sum
            prefixSum += arr[i];

            // Calculate the prefix sum that needs to be removed
            int remove = prefixSum - k;

            // If this prefix sum has been seen before,
            // add its count to the result
            if (prefixSumCount.find(remove) != prefixSumCount.end()) {
                count += prefixSumCount[remove];
            }

            // Update the frequency of the current prefix sum
            prefixSumCount[prefixSum]++;
        }

        return count;
    }
};

/*
╭──────────────────────────────────────────────────────────────╮
│                        Complexity                            │
├──────────────────────────────────────────────────────────────┤
│  Time  : O(N)  (average case)                                │
│  Space : O(N)                                                │
│--------------------------------------------------------------│
│  Note  : Single traversal using prefix sum                   │
│          HashMap stores prefix frequencies                   │
│          Lookup & update are O(1) average                    │
╰──────────────────────────────────────────────────────────────╯
*/

// Link: https://leetcode.com/problems/subarray-sum-equals-k/description/