#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.length() - 1;

        for(int i = n ; i >= 0 ; i--){

            if(num[i]%2){
                return num.substr(0 , i+1);
            }
        }

        return "";
        
    }
};

/*
Time Complexity: O(N), since the loop runs once through the string of length N.

Space Complexity: O(1), as we are using only a constant amount of extra space.
*/