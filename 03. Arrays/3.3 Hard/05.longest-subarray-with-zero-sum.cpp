#include <bits/stdc++.h>
using namespace std;

int maxLength(vector<int>& arr) {
    int n = arr.size();
    
    // prefixSum -> first index
    unordered_map<int, int> firstSeen; 
    int prefixSum = 0;
    int maxLen = 0;

    // insert prefix sum 0 at index -1
    // to handle sum from start
    firstSeen[0] = -1;

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];

        // prefix sum has been seen before
        if (firstSeen.find(prefixSum) != firstSeen.end()) {
            int prevIndex = firstSeen[prefixSum];
            int length = i - prevIndex;
            maxLen = max(maxLen, length);
        }
        else {
            
            // Store first occurrence of this prefix sum
            firstSeen[prefixSum] = i;
        }
    }

    return maxLen;
}

/*
╭──────────────────────────────────────────────────────────────╮
│                        Complexity                            │
├──────────────────────────────────────────────────────────────┤
│  Time  : O(N)  (average case)                                │
│  Space : O(N)                                                │
│--------------------------------------------------------------│
│  Note  : Prefix sum computed in single traversal             │
│          HashMap stores first occurrence of each sum         │
│          Repeated sum ⇒ subarray with sum = 0               │
╰──────────────────────────────────────────────────────────────╯
*/

// The idea is based on the observation that for two different indices i and j (where j > i) if the prefix sums Si and Sj are equal, it means that the sum of the elements between indices i+1 and j is zero.