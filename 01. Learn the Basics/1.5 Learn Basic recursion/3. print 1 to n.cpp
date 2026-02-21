#include <bits/stdc++.h>
using namespace std;

// Forward Recursion: 1 → n
class Solution {
public:
    void printNumbers(int current, int n) {
        // Base case: if current exceeds n, stop recursion
        if (current > n)
            return;

        // Print current number
        cout << current << " ";

        // Recursive call with next number
        printNumbers(current + 1, n);
    }
};


// Backtracking Recursion: n → 1
class Solution {
public:
    void printNumbers(int current, int n) {
        // Base case: if current exceeds n, stop recursion
        if (current > n)
            return;

        // Recursive call with next number
        printNumbers(current + 1, n);

        // Print current number during backtracking
        cout << current << " ";
    }
};

/*
╭─────────────────────────────────────────────────────────────╮
│                      Complexity                             │
├─────────────────────────────────────────────────────────────┤
│  Time  : O(N)                                               │
│  Space : O(N)                                               │
│-------------------------------------------------------------│
│  Notes : N recursive calls                                  │
│          Space due to recursion stack                       │
│          Forward prints during descent                      │
│          Backward prints during backtracking                │
╰─────────────────────────────────────────────────────────────╯
*/