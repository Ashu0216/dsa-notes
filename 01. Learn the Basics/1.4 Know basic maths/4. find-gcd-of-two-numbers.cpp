#include <bits/stdc++.h>
using namespace std;

// Brute Force
int main() {
    int a = 12, b = 16;
    int res = min(a, b);
    while (res > 1) {
        if (a % res == 0 && b % res == 0)
            break;
        res--;
    }
    cout <<res;
    return 0;
}

// Euclidean Algorithm
int gcd(int a, int b) {
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    if (a == b)
        return a;
    if (a > b)
        return gcd(a - b, b);

    return gcd(a, b - a);
}

//shorter Euclidean Algorithm

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
