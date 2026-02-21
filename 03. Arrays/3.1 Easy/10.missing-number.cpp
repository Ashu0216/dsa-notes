#include <iostream>
#include <vector>
using namespace std;

// Approach 1: Using Sum of n terms Formula - O(n) Time and O(1) Space

// The sum of the first n natural numbers is given by the formula (n * (n + 1)) / 2. The idea is to compute this sum and subtract the sum of all elements in the array from it to get the missing number.

int missingNum(vector<int> &arr) {
    int n = arr.size() + 1;
  
    // Calculate the sum of array elements
    int sum = 0;
    for (int i = 0; i < n - 1; i++) {
        sum += arr[i];
    }

    // Calculate the expected sum
    long long expSum = (n *1LL* (n + 1)) / 2;  

    // Return the missing number
    return expSum - sum;
}

/*
╭──────────────────────────────────────╮
│              Complexity              │
├──────────────────────────────────────┤
│  Time  : O(N)                        │
│  Space : O(1)                        │
│--------------------------------------│
│  Notes  : Single pass traversal      │
│           No extra data structure    │
╰──────────────────────────────────────╯
*/

// Approach 2: Using XOR Operation - O(n) Time and O(1) Space

int missingNum(vector<int>& arr) {
    int n = arr.size() + 1;
    int xor1 = 0, xor2 = 0;

    // XOR all array elements
    for (int i = 0; i < n - 1; i++) {
        xor2 ^= arr[i];
    }

    // XOR all numbers from 1 to n
    for (int i = 1; i <= n; i++) {
        xor1 ^= i;
    }

    // Missing number is the XOR of xor1 and xor2
    return xor1 ^ xor2;
}

/*
╭──────────────────────────────────────╮
│              Complexity              │
├──────────────────────────────────────┤
│  Time  : O(N)                        │
│  Space : O(1)                        │
│--------------------------------------│
│  Notes  : Single pass traversal      │
│           No extra data structure    │
╰──────────────────────────────────────╯
*/