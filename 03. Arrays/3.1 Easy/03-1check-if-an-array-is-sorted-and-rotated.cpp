#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    bool check(vector<int>& nums) {

        int count = 0;

        int length = nums.size();

        if(length == 1){
            return true;
        }

        for (int i = 1 ; i< length ; i++){
            if( nums[i] < nums[i-1]) 
                count++;
        }

        if(nums[0] <  nums[length-1]){
            count++;
        }
        
        return (count<2);
    }
};

/*
╭──────────────────────────────────────────────────────────────╮
│              Complexity                                      │
├──────────────────────────────────────────────────────────────┤
│  Time  : O(N)                                                │
│  Space : O(1)                                                │
│--------------------------------------------------------------│
│  Notes  : checks each adjacent pair once in a single pass    │
│           No extra data structure                            │
╰──────────────────────────────────────────────────────────────╯
*/

// Link: https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/