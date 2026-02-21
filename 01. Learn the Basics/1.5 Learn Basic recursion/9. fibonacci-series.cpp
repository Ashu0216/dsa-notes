#include <bits/stdc++.h>
using namespace std;

int fibonacci(int N) {
    // Base case: if N is 0 or 1, return N itself
    if (N <= 1) {
        return N;
    }

    int last = fibonacci(N - 1);   
    int slast = fibonacci(N - 2);  

    return last + slast;
}

// Input: N = 5
// Output: 0 1 1 2 3 5

// Link: https://leetcode.com/problems/fibonacci-number/description/