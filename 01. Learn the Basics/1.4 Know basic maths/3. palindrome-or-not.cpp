#include <iostream>
using namespace std;

bool palindrome(int n) {
    int revNum = 0; 
    int dup = n; 

    while (n > 0) {
        int ld = n % 10; 
        revNum = (revNum * 10) + ld;
        n = n / 10; 
    }

    // Check if the original number is equal to its reverse
    if (dup == revNum) {
        return true; 
    } else {
        return false; 
    }
}

/*
╭──────────────────────────────────────────────────────────────╮
│                      Complexity                              │
├──────────────────────────────────────────────────────────────┤
│  Time  : O(log₁₀ N)                                          │
│  Space : O(1)                                                │
│--------------------------------------------------------------│
│  Notes : One pass over digits                                │
│          Number of iterations = number of digits             │
╰──────────────────────────────────────────────────────────────╯
*/

//Link: https://leetcode.com/problems/palindrome-number/description/