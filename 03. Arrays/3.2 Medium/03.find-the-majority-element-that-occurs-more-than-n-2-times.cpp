#include <bits/stdc++.h>
using namespace std;

// Boyer–Moore Voting Algorithm 

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int n = nums.size();
        int cnt = 0;
        int el; 
        
        for (int i = 0; i < n; i++) {
            if (cnt == 0) {
                cnt = 1;
                el = nums[i];
            } else if (el == nums[i]) {
                cnt++;
            } else {
                cnt--;
            }
        }
        
        /* Checking if the stored element
         is the majority element*/
        int cnt1 = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == el) {
                cnt1++;
            }
        }
        
        //return element if it is a majority element
        if (cnt1 > (n / 2)) {
            return el;
        }
        
        //return -1 if no such element found
        return -1;
    }
};

/*
╭──────────────────────────────────────────────────────────────╮
│                        Complexity                            │
├──────────────────────────────────────────────────────────────┤
│  Time  : O(N)                                                │
│  Space : O(1)                                                │
│--------------------------------------------------------------│
│  Algo  : Boyer–Moore Voting Algorithm                        │
│  Notes : First pass finds candidate                          │
│          Second pass verifies majority                       │
│          Uses constant extra space                           │
╰──────────────────────────────────────────────────────────────╯
*/