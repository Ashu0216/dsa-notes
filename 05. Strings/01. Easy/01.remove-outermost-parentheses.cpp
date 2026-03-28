#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string removeOuterParentheses(string s) {

        string res;
        int count = 0;

        for(int i = 0 ; i < s.length() ; i++){
            char c = s[i];

            if(c == '('){
                if( count >= 1){
                    res = res + '(';
                }
                count++;
            }else{
                if(count >1)
                    res = res + ')';
                count--;
            }
        }

        return res;

        
    }
};

// Time Complexity: O(n), since we are performing a single traversal of the string.

// Space Complexity: O(1), since we are using a few variables to track the current state.

// Link: https://leetcode.com/problems/remove-outermost-parentheses/
