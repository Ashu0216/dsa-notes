#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int longestConsecutive(vector<int> &arr) {
    unordered_set<int> st;
    int res = 0;

    // Hash all the array elements
    for (int val: arr)
        st.insert(val);

    // check each possible sequence from the start then update optimal length
    for (int val: arr) {
      
        // if current element is the starting element of a sequence
        if (st.find(val) != st.end() && st.find(val-1) == st.end()) {
          
            // Then check for next elements in the sequence
            int cur = val, cnt = 0;
            while (st.find(cur) != st.end()) {
                
                // Remove this number to avoid recomputation
                st.erase(cur);
                cur++;
              	cnt++;
            }

            // update  optimal length
            res = max(res, cnt);
        }
    }
    return res;
}

/*
The idea is to use Hashing. We first insert all elements in a Hash Set. Then, traverse over all the elements and check if the current element can be a starting element of a consecutive subsequence. If it is then start from X and keep on removing elements X + 1, X + 2 .... to find a consecutive subsequence.

To check if the current element, say X can be a starting element, check if (X - 1) is present in the set. If (X - 1) is present in the set, then X cannot be starting of a consecutive subsequence.
*/

/*
╭──────────────────────────────────────────────────────────────╮
│                        Complexity                            │
├──────────────────────────────────────────────────────────────┤
│  Time  : O(N)  (average case)                               │
│  Space : O(N)                                               │
│--------------------------------------------------------------│
│  Note  : Hash set stores unique elements                    │
│          Each element processed at most once                │
│          Sequence starts checked only at valid beginnings   │
╰──────────────────────────────────────────────────────────────╯
*/

// Link: https://leetcode.com/problems/longest-consecutive-sequence/editorial/
