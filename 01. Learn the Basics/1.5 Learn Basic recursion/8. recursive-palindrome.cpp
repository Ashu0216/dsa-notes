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

    return isPalindromeRec(s, left + 1, right - 1);
}

bool isPalindrome(string& s) {
    return isPalindromeRec(s, 0, s.size() - 1);
}

/*
╭─────────────────────────────────────────────────────────────╮
│                         Complexity                          │
├─────────────────────────────────────────────────────────────┤
│  Time  : O(N)                                               │
│  Space : O(N)                                               │
│-------------------------------------------------------------│
│  Notes : N recursive calls in worst case                    │
│          Space due to recursion stack                       │
╰─────────────────────────────────────────────────────────────╯
*/