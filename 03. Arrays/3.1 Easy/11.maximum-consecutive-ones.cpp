#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {

        int len = 0;
        int cnt = 0;

        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] == 1){
                cnt++;
                len = max(len , cnt);
            }
            else{
                cnt = 0;
            }
        }

        return len;
        
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

// Link: https://leetcode.com/problems/max-consecutive-ones/