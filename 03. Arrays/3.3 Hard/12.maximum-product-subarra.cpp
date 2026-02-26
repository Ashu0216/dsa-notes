#include <bits/stdc++.h>
using namespace std;

// Approach - 1: Greedy Min-Max Product - O(n) Time and O(1) Space

int maxProduct(vector<int> &arr) {

  	int n = arr.size();
  	
    // max product ending at the current index
    int currMax = arr[0];

    // min product ending at the current index
    int currMin = arr[0];

    // Initialize overall max product
    int maxProd = arr[0];
  
    // Iterate through the array 
    for (int i = 1; i < n; i++) {
      	
      	// Temporary variable to store the maximum product ending 
      	// at the current index
        int temp = max({ arr[i], arr[i] * currMax,
                        					arr[i] * currMin });
        
      	// Update the minimum product ending at the current index
      	currMin = min({ arr[i], arr[i] * currMax,
                    						arr[i] * currMin });
      
      	// Update the maximum product ending at the current index
        currMax = temp;
      
      	// Update the overall maximum product
        maxProd = max(maxProd, currMax);
    }
    return maxProd;
}

/*
╭──────────────────────────────────────────────────────────────╮
│                        Complexity                            │
├──────────────────────────────────────────────────────────────┤
│  Time  : O(N)                                                │
│  Space : O(1)                                                │
│--------------------------------------------------------------│
│  Note  : Single pass traversal                               │
│          Only constant variables used                        │
╰──────────────────────────────────────────────────────────────╯
*/

// Approach - 2 : By Traversing in Both Directions - O(n) Time and O(1) Space

int maxProduct(vector<int> &arr) {

  	int n = arr.size();
    int maxProd = INT_MIN;
  
    // leftToRight to store product from left to Right
    int leftToRight = 1;
  
    // rightToLeft to store product from right to left
    int rightToLeft = 1;
  
    for (int i = 0; i < n; i++) {
        if (leftToRight == 0)
            leftToRight = 1;
        if (rightToLeft == 0)
            rightToLeft = 1;
      
        // calculate product from index left to right
        leftToRight *= arr[i];
      
        // calculate product from index right to left
        int j = n - i - 1;
        rightToLeft *= arr[j];
        maxProd = max({leftToRight, rightToLeft, maxProd});
    }
    return maxProd;
}

/*
╭──────────────────────────────────────────────────────────────╮
│                        Complexity                            │
├──────────────────────────────────────────────────────────────┤
│  Time  : O(N)                                                │
│  Space : O(1)                                                │
│--------------------------------------------------------------│
│  Note  : Two linear traversals                               │
│          No extra data structures used                       │
╰──────────────────────────────────────────────────────────────╯
*/

// Link: https://leetcode.com/problems/maximum-product-subarray/description/
