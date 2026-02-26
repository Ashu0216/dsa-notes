#include <iostream>
#include <vector>
using namespace std;

// [Approach 1] Using Array Marking - O(n) Time and O(1) Space

vector<int> findTwoElement(vector<int>& arr) {
    int n = arr.size();
    int repeating = -1;

    // mark visited indices by negating the value at
    // that index
    for (int i = 0; i < n; i++) {
        int val = abs(arr[i]);

        if (arr[val - 1] > 0) {
            arr[val - 1] = -arr[val - 1];
        } else {
            // found the repeating element
            repeating = val;
        }
    }

    int missing = -1;

    // the index with a positive value is the 
    // missing number
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            missing = i + 1;
            break;
        }
    }

    return {repeating, missing};
}


/*
╭──────────────────────────────────────────────────────────────╮
│                        Complexity                            │
├──────────────────────────────────────────────────────────────┤
│  Time  : O(N)                                               │
│  Space : O(1)                                               │
│--------------------------------------------------------------│
│  Note  : Two linear passes                                  │
│          In-place marking using sign change                 │
╰──────────────────────────────────────────────────────────────╯
*/

// [Approach 2] Making Two Math Equations - O(n) Time and O(1) Space

vector<int> findTwoElement(vector<int>& arr) {
    int n = arr.size();

    // Sum of first n natural numbers
    int  s = (n * (n + 1)) / 2;
    // Sum of squares of first n natural numbers
    int ssq = (n * (n + 1) * (2 * n + 1)) / 6;

    // Subtract actual values from expected sums
    for (int i = 0; i < n; i++) {
        s -= arr[i];
        ssq -= arr[i] * arr[i];
    }

    // Using the equations: missing - repeating = s
    // missing^2 - repeating^2 = ssq
    int missing = (s + ssq / s) / 2;
    int repeating = missing - s;

    return {repeating, missing};
}

/*
╭──────────────────────────────────────────────────────────────╮
│                        Complexity                            │
├──────────────────────────────────────────────────────────────┤
│  Time  : O(N)                                               │
│  Space : O(1)                                               │
│--------------------------------------------------------------│
│  Note  : Single traversal for sum calculations              │
│          Uses mathematical formulae                         │
╰──────────────────────────────────────────────────────────────╯
*/


// [Approach 3] Using XOR - O(n) Time and O(1) Space

vector<int> findTwoElement(vector<int>& arr) {
    int n = arr.size();
    int xorVal = 0;  

    // get the xor of all array elements
    // and numbers from 1 to n
    for (int i = 0; i < n; i++) {
        xorVal ^= arr[i];
        xorVal ^= (i + 1);  // 1 to n numbers
    }

    // get the rightmost set bit in xorVal
    int setBitIndex = xorVal & ~(xorVal - 1);
    
    int x = 0, y = 0;

    // now divide elements into two sets 
    // by comparing rightmost set bit
    for (int i = 0; i < n; i++) {
      
        // decide whether arr[i] is in first set 
        // or second
        if (arr[i] & setBitIndex) { 
            x ^= arr[i]; 
        }  
        else { 
            y ^= arr[i]; 
        } 
      
        // decide whether (i+1) is in first set 
        // or second
        if ((i+1) & setBitIndex) { 
            x ^= (i + 1); 
        }
        else { 
            y ^= (i + 1); 
        }
    }

    // x and y are the repeating and missing values.
    // to know which one is what, traverse the array 
    int missing, repeating;
    
    int xCnt = 0;
    for (int i=0; i<n; i++) {
        if (arr[i] == x) {
            xCnt++;
        }
    }
    
    if (xCnt == 0) {
        missing = x;
        repeating = y;
    }
    else {
        missing = y;
        repeating = x;
    }
    
    return {repeating, missing};
}


/*
╭──────────────────────────────────────────────────────────────╮
│                       Algorithm                              │
├──────────────────────────────────────────────────────────────┤
│  1. XOR all array elements with numbers 1 to N               │
│     → result = missing ^ repeating                           │
│  2. Find rightmost set bit of XOR result                     │
│  3. Divide numbers into two groups using this bit            │
│  4. XOR each group separately → get x and y                  │
│  5. Check frequency to identify missing & repeating          │
│                                                              │
│  Idea : XOR cancels equal numbers, isolates two values       │
╰──────────────────────────────────────────────────────────────╯
*/

/*
╭──────────────────────────────────────────────────────────────╮
│                        Complexity                            │
├──────────────────────────────────────────────────────────────┤
│  Time  : O(N)                                                │
│  Space : O(1)                                                │
│--------------------------------------------------------------│
│  Note  : Multiple linear XOR passes                          │
│          Bit manipulation used for partitioning              │
╰──────────────────────────────────────────────────────────────╯
*/