#include <bits/stdc++.h>
using namespace std;

// forward recusrion
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


// backtracking recursion
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