#include <bits/stdc++.h>
using namespace std;

// Upper Bound:  The upper bound of a number is defined as the smallest index in the sorted array where the element is greater than the given number.

// Using Binary Search - O(log n) Time and O(1) Space

int upperBound(vector<int> &arr, int target) { 	
	int lo = 0, hi = arr.size() - 1; 
    int res = arr.size();
  	
  	while(lo <= hi) {
      	int mid = lo + (hi - lo)/2;

      	if(arr[mid] > target) {
          	res = mid;
            hi = mid - 1;
        }
      	else
            lo = mid + 1;
    }
  	return res;
}

// Using Built-In Methods - O(log n) Time and O(1) Space

int upperBound(vector<int> &arr, int target) {
    
   // Using inbuilt method
   int index = upper_bound(arr.begin(), arr.end(), target) - arr.begin();
  
   return index;
}
