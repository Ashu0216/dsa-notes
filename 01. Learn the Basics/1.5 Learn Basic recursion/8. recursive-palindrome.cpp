#include <iostream>
#include <string>
using namespace std;

// Helper recursive function to check palindrome
bool isPalindromeRec(string& s, int left, int right) {
    
    // Base case
    if (left >= right) 
        return true;
    
    // If mismatch found
    if (s[left] != s[right]) 
        return false;

    // Recursive call with narrowed range
    return isPalindromeRec(s, left + 1, right - 1);
}

bool isPalindrome(string& s) {
    return isPalindromeRec(s, 0, s.size() - 1);
}