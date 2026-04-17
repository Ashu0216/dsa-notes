#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDepth(string s) {

        int count = 0;
        int maxi = 0;

        for(int i = 0 ; i < s.length() ; i++){
            char ch = s[i];
            if(ch== '('){
                count ++;
                maxi = max(count , maxi);
            }else if(ch==')'){
                count --;
            }
        }
        return maxi;
    }
};

/*
Time Complexity: O(n), where n is the length of the string.

Space Complexity: O(1), as only constant extra space is used.
*/

// Link: https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/