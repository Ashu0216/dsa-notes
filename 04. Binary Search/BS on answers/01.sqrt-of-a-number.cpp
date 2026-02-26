#include <bits/stdc++.h>
using namespace std;

int floorSqrt(int n) {
  
    // initial search space
    int lo = 1, hi = n;
    int res = 1;
    
    while(lo <= hi) {
        int mid = lo + (hi - lo)/2;
        
        // if square of mid is less than or equal to n 
        // update the result and search in upper half
        if(mid*mid <= n) {
            res = mid;
            lo = mid + 1;
        }
        
        // if square of mid exceeds n, 
      	// search in the lower half
        else {
            hi = mid - 1;
        }
    }
    
    return res;
}

// With precision

double squareRoot(int n, int p) {
    int start = 0, end = n;
    int mid;
    double ans = 0.0;

    // Binary search for integral part
    while (start <= end) {
        mid = (start + end) / 2;
        if (mid * mid == n) {
            ans = mid;
            break;
        }
        if (mid * mid < n) {
            ans = mid;
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    // Binary-like refinement 
    // for decimal places
    double increment = 0.1;
    for (int i = 0; i < p; i++) {
        while ((ans + increment) * (ans + increment) <= n) {
            ans += increment;
        }
        increment /= 10;
    }

    return ans;
}

/*

Step by Step Approach

Finding the Integer Part using Binary Search

1. The square root of n lies between 0 and n (inclusive)
2. Using binary search in this range to find the largest integer x such that x*x <= n.
  => Initialize start = 0, end = n, and ans = 0.
  => While start ≤ end:
  => Compute mid = (start + end) / 2
  => If mid * mid == n, you've found the exact square root.
  => If mid * mid < n, store ans = mid, and search the right half (start = mid + 1).
  => If mid * mid > n, search the left half (end = mid - 1).
3. This gives the integer part of the square root (i.e., floor(√n))


Decimal Precision

1. Now refine the answer by adding decimal values incrementally.
2. Start with increment = 0.1 and repeat for p digits of precision.
For each digit:
  => While (ans + increment)^2 ≤ n, keep increasing ans by increment.
  => Once you exceed n, backtrack (don't update ans) and reduce increment by a factor of 10:
  => 0.1 → 0.01 → 0.001 → ... (for p times)
3. This process helps add one decimal digit of precision per iteration.

*/