#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.length() != t.length()) return false;

        unordered_map <char , int> mp;

        for( char c: s)
            mp[c]++;
        for( char c: t)
            mp[c]--;

        for(auto it: mp){
            if(it.second != 0)
                return false;
        }
        
        return true;
        
    }
};

/*
Time complexity: O(N)
Space complexity: O(N)
*/

// Link: https://leetcode.com/problems/valid-anagram/description/