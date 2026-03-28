#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin() , strs.end());

        int n = strs.size();
        string first = strs[0] , last = strs[n-1];
        string res;

        for(int i = 0 ; i < last.length(); i++){
            if(first[i] == last[i] ){
                res = res + first[i];
            }
            else{
                break;
            }
        }
        return res;
    }
};

/*
Time Complexity: O(N * log N + M), where N is the number of strings and M is the minimum length of a string. The sorting operation takes O(N * log N) time, and the comparison of characters in the first and last strings takes O(M) time.

Space Complexity: O(M), as the ans variable can store the length of the prefix which in the worst case will be O(M).
*/

// Link: https://leetcode.com/problems/longest-common-prefix/
