#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {

        if(s.empty()) return 0;

        int i = 0;
        int n = s.length();

        // Step1: skip leading spaces
        while( i <n && s[i] == ' '){
            i++;
        }

        // check if we have reached the end
        if(i == n){
            return 0;
        }

        // step2: check sign
        int sign = 1;
        if(s[i] == '+'){
            i++;
        }
        else if (s[i] == '-'){
            sign = -1;
            i++;
        }

        // step3: read digits and convert
        long long res = 0;
        while( i < n && isdigit(s[i])){
            int digit = s[i] - '0';
            res = res * 10 + digit;

            if(sign* res <= INT_MIN){
                return INT_MIN;
            }
            if(sign* res >= INT_MAX){
                return INT_MAX;
            }

            i++;
        }

        // Step 4: Apply sign and return
        return static_cast<int>(res*sign);

    }
};

/*
Time complexity: O(n)
Space complexity: O(1)
*/

// Link: https://leetcode.com/problems/string-to-integer-atoi