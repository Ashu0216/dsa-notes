#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverseNumber(int n) {
        
        int revNum = 0;

        // Loop until all digits are processed
        while (n > 0) {
            // Get the last digit
            int lastDigit = n % 10;

            // Append it to the reversed number
            revNum = revNum * 10 + lastDigit;

            // Remove the last digit from n
            n = n / 10;
        }

        // Return the reversed number
        return revNum;
    }
};

//Link: https://leetcode.com/problems/reverse-integer/description/
