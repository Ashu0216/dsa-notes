#include <bits/stdc++.h>
using namespace std;

int fibonacci(int N) {
    // Base case: if N is 0 or 1, return N itself
    if (N <= 1) {
        return N;
    }

    return fibonacci(N - 1) + fibonacci(N - 2);
}

/*
╭──────────────────────────────────────────────────────────────╮
│                         Complexity                           │
├──────────────────────────────────────────────────────────────┤
│  Time  : O(2^N)                                              │
│  Space : O(N)                                                │
│--------------------------------------------------------------│
│  Notes : Exponential due to overlapping subproblems          │
│          Stack depth up to N                                 │
╰──────────────────────────────────────────────────────────────╯
*/

// Input: N = 5
// Output: 0 1 1 2 3 5

// Link: https://leetcode.com/problems/fibonacci-number/description/