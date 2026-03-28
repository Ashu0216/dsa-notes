#include<bits/stdc++.h>
using namespace std;

// Using inbuild functions for substring
class Solution {
public:
    string reverseWords(string s) {

        int i = s.size()-1;
        string res;

        while (i>=0){

            while(i>=0 && s[i]==' ')i--;
            if(i<0) break;

            int end = i;

            while (i>=0 && s[i]!=' ')i--;

            int start = i;

            if(res.empty()){
                res = s.substr(i+1, end-start);
            }
            else{
                res = res + " " + s.substr(i+1, end-start);
            }
        }

        return res;
        
    }
};

// wihtout using inbuild functions
class Solution {
public:
    string reverseWords(string s) {
        
        string res;
        string word;

        int i = s.length() - 1;

        while (i >= 0){
            if( i>= 0  && s[i] == ' '){
                i--;
                continue;
            }

            if(s[i] != ' '){
                word = s[i] + word;
            }

            if( i== 0 || s[i-1] == ' '){
                if(res.empty()){
                    res = res + word;
                }
                else{
                    res = res + ' ' + word;
                }
                word = "";
            }
            i--;
        }

        return res;
    }
};

// Time Complexity: O(N), We traverse the string once from right to left and construct the result directly without extra passes.

// Space Complexity: O(1),Ignoring the output string, no additional data structures proportional to input size are used.

// Link: https://leetcode.com/problems/reverse-words-in-a-string/