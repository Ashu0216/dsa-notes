#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverseNumber(int n) {
        int rev = 0;

        while (n > 0) {
            rev = rev * 10 + (n % 10);
            n /= 10;
        }

        return rev;
    }
};

/*
╭──────────────────────────────────────────────────────────────╮
│                      Complexity                              │
├──────────────────────────────────────────────────────────────┤
│  Time  : O(log₁₀ N)                                          │
│  Space : O(1)                                                │
│--------------------------------------------------------------│
│  Notes : Each iteration removes one digit (divide by 10)     │
│          Number of iterations = number of digits             │
╰──────────────────────────────────────────────────────────────╯
*/

//Link: https://leetcode.com/problems/reverse-integer/description/
