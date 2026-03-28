#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char , int>  mp1 , mp2;
 
        if(s.length() != t.length()) return false;

        for (int i = 0 ;  i < s.length() ; i++){
            if(mp1[s[i]] != mp2[t[i]]) 
                return false;

            mp1[s[i]] = i+1;
            mp2[t[i]] = i+1;
        }

        return true;
    }
};

/*
Time Complexity: O(N) where N is the length of the input strings, due to the single loop iterating through each character.

Space Complexity: O(1) since the space used by the arrays is constant (256 fixed size) regardless of input size
*/

// Link: https://leetcode.com/problems/isomorphic-strings/description/