#include <iostream>
using namespace std;

// iterative
int factorial(int X) {
    int ans = 1;

    // Loop from 1 to X to compute factorial
    for (int i = 1; i <= X; i++) {
        ans = ans * i;
    }

    // Return the final result
    return ans;
}

// Recursive function to calculate factorial of a number
int factorial(int n) {
    // Base case: factorial of 0 is 1
    if (n == 0) {
        return 1;
    }

    // Recursive case: n * factorial of (n-1)
    return n * factorial(n - 1);
}