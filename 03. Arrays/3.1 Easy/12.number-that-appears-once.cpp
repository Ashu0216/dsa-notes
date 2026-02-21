#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getSingleElement(vector<int>& arr) {
        int n = arr.size();
        int xorr = 0;

        // XOR all elements. Duplicates cancel out, leaving the single element.
        for (int i = 0; i < n; i++) {
            xorr = xorr ^ arr[i];
        }

        return xorr;
    }
};


/*
╭──────────────────────────────────────╮
│              Complexity              │
├──────────────────────────────────────┤
│  Time  : O(N)                        │
│  Space : O(1)                        │
│--------------------------------------│
│  Notes  : Single pass traversal      │
│           No extra data structure    │
╰──────────────────────────────────────╯
*/