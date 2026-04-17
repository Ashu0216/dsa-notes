#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {

        int ans = 0 ;
        int n = s.length();

        unordered_map <char , int> m;

        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;

        for(int i = 0 ; i < n ; i++){
            if(i < n-1 && m[s[i]] < m[s[i+1]]){
                ans -= m[s[i]];
            }
            else{
                ans += m[s[i]];
            }
        }

        return ans;
        
    }
};

/*
Time Complexity: O(n), where n is the length of the input string since we traverse the string once.
Space Complexity: O(1), since we use a fixed-size map for Roman numerals.

*/

// Link: https://leetcode.com/problems/roman-to-integer/