#include <bits/stdc++.h>
using namespace std;

// Brute Force
int gcdBrute(int a, int b) {
    int res = min(a, b);

    while (res > 0) {
        if (a % res == 0 && b % res == 0)
            return res;
        res--;
    }

    return 1;
}

// Euclidean Algorithm
int gcd(int a, int b)
{
    if (b == 0) return a;
    if (a == 0) return b;
    
    if (a > b)
        return gcd(a - b, b);
    else
        return gcd(a, b - a);
}

// Optimized Euclidean Algorithm (Modulo based)
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

/*
╭─────────────────────────────────────────────────────────────╮
│                      Complexity                             │
├─────────────────────────────────────────────────────────────┤
│  Brute Force                                                │
│  Time  : O(min(a, b))                                       │
│  Space : O(1)                                               │
│-------------------------------------------------------------│
│  Subtraction Method                                         │
│  Time  : O(max(a, b)) (worst case)                          │
│  Space : O(max(a, b)) recursion depth                       │
│-------------------------------------------------------------│
│  Modulo Method (Optimal)                                    │
│  Time  : O(log(min(a, b)))                                  │
│  Space : O(log(min(a, b))) recursion depth                  │
│-------------------------------------------------------------│
│  Notes : Modulo-based Euclidean algorithm is optimal        │
╰─────────────────────────────────────────────────────────────╯
*/