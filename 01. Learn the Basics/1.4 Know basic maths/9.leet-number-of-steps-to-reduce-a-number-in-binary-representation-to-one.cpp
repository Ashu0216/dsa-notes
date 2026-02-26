#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSteps(string s) {
        int steps = 0;
        int carry = 0;

        // traverse from right to left (ignore first bit)
        for (int i = s.length() - 1; i > 0; i--) {

            int bit = (s[i] - '0') + carry;

            if (bit == 1) {
                // odd -> add 1 then divide
                steps += 2;
                carry = 1;
            } else {
                // even -> just divide
                steps += 1;
                // carry remains same
            }
        }

        // if carry still 1 at MSB
        return steps + carry;
    }
};

/*
╭──────────────────────────────────────────────────────────────╮
│                          Algorithm                           │
├──────────────────────────────────────────────────────────────┤
│  1. Initialize:                                              │
│       - steps = 0                                            │
│       - carry = 0                                            │
│                                                              │
│  2. Traverse string from right to left                       │
│     (ignore the first bit at index 0)                        │
│                                                              │
│  3. For each bit:                                            │
│       - Compute: bit = (current_bit - '0') + carry           │
│                                                              │
│       - If bit == 1 (odd):                                   │
│            → steps += 2  (add 1 + divide by 2)               │
│            → carry = 1                                       │
│                                                              │
│       - Else (bit == 0 or 2 → even):                         │
│            → steps += 1  (only divide by 2)                  │
│            → carry remains same                              │
│                                                              │
│  4. After loop ends:                                         │
│       - If carry == 1 → one extra divide needed              │
│                                                              │
│  5. Return steps + carry                                     │
│                                                              │
│  Idea : Instead of modifying the string, simulate binary     │
│         addition using a carry variable in one pass.         │
╰──────────────────────────────────────────────────────────────╯
*/


/*
╭──────────────────────────────────────────────────────────────╮
│                         Complexity                           │
├──────────────────────────────────────────────────────────────┤
│  Time  : O(N)                                                │
│          (Single right-to-left traversal)                    │
│                                                              │
│  Space : O(1)                                                │
│          (Only two integer variables used)                   │
│--------------------------------------------------------------│
│  Note  : No string modification or big integer conversion    │
│          Avoids O(N²) behavior of repeated carry handling    │
╰──────────────────────────────────────────────────────────────╯
*/


// Link: https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one