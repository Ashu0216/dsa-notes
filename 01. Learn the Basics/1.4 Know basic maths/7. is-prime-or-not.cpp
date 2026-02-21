#include <bits/stdc++.h>
using namespace std;

bool checkPrime(int n)
{
    int cnt = 0;
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            cnt++; // If n is divisible by i, increment the counter

            // If n is not a perfect square, count its reciprocal factor
            if (n / i != i)
            {
                cnt++;
            }
        }
    }

    // If the number of factors is exactly 2 (1 and the number itself), it's prime
    if (cnt == 2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*
╭──────────────────────────────────────────────────────────────╮
│                      Complexity                              │
├──────────────────────────────────────────────────────────────┤
│  Time  : O(√N)                                               │
│  Space : O(1)                                                │
│--------------------------------------------------------------│
│  Notes : Checks divisibility up to √N                        │
│          Stops early on first divisor                        │
╰──────────────────────────────────────────────────────────────╯
*/