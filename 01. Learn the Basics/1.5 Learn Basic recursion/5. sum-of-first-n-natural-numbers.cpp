#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumOfNaturalNumbers(int N) {
        // Base case: if N is 1, return 1
        if (N == 1) {
            return 1;
        }

        return N + sumOfNaturalNumbers(N - 1);
    }
};
