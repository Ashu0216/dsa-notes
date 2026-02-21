#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;

        int i = 0;

        for (int j = 1; j < nums.size(); j++) {
            // If current element is different from last unique element
            if (nums[j] != nums[i]) {
                
                i++; // Move pointer for unique element forward
                
                nums[i] = nums[j]; // Place the new unique element at the next position
            }
        }

        // i is index of last unique element, count = i + 1
        return i + 1;
    }
};

/*
╭──────────────────────────────────────────────────────────────╮
│              Complexity                                      │
├──────────────────────────────────────────────────────────────┤
│  Time  : O(N)                                                │
│  Space : O(1)                                                │
│--------------------------------------------------------------│
│  Notes  : We traverse the entire original array only once    │
│           No extra data structure                            │
╰──────────────────────────────────────────────────────────────╯
*/