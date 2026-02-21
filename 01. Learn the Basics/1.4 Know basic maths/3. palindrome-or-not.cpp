#include <iostream>
using namespace std;

bool palindrome(int n) {
    int revNum = 0; // Initialize a variable to store the reverse of the number
    int dup = n; // Create a duplicate variable to store the original number

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

//Link: https://leetcode.com/problems/palindrome-number/description/