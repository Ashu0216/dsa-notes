#include <bits/stdc++.h>
using namespace std;

class ArmstrongChecker {
public:
    static bool isArmstrong(int num) {
        int k = to_string(num).length(); 
        int sum = 0;
        int n = num;

        while (n > 0) {
            int ld = n % 10;            // Get last digit
            sum += pow(ld, k);          // Add ld^k to sum
            n /= 10;                    // Remove last digit
        }

        return sum == num; 
    }
};

/*
╭──────────────────────────────────────────────────────────────╮
│                      Complexity                              │
├──────────────────────────────────────────────────────────────┤
│  Time  : O(d)                                               │
│  Space : O(1)                                               │
│--------------------------------------------------------------│
│  Notes : d = number of digits in num                        │
│          Each digit processed once                          │
│          pow() runs in constant time (small exponent)       │
╰──────────────────────────────────────────────────────────────╯
*/

// Input:N = 153
// Output:True
// Explanation: 1^3+5^3+3^3 = 1 + 125 + 27 = 153