#include <iostream>
using namespace std;

int countDigits(int n) {
    int cnt = 0;

    // Handle negative numbers
    n = abs(n);

    // Special case: 0 has 1 digit
    if (n == 0) return 1;

    while (n > 0) {
        cnt++;
        n /= 10;
    }

    return cnt;
}

/*
╭──────────────────────────────────────────────────────────────╮
│                      Complexity                              │
├──────────────────────────────────────────────────────────────┤
│  Time  : O(log₁₀ N)                                          │
│  Space : O(1)                                                │
│--------------------------------------------------------------│
│  Notes : Number of iterations equals number of digits        │
│          (division by 10 each step)                          │
╰──────────────────────────────────────────────────────────────╯
*/