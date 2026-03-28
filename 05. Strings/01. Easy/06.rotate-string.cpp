#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {

        if(s.length() != goal.length()) return false;
        
        string doubledString = s + s;

        return doubledString.find(goal) < doubledString.length();
    }
};

/*
Time Complexity: O(N), because checking for a substring in s + s is linear in time.

Space Complexity: O(N) for the space needed to store the concatenated string s + s.
*/

// Link: https://leetcode.com/problems/rotate-string/