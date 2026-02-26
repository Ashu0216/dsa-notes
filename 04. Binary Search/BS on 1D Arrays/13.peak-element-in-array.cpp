#include <bits/stdc++.h>
using namespace std;

int peakElement(vector<int> &arr) {
    int n = arr.size();
  
    // If there is only one element, then it's a peak
    if (n == 1) 
        return 0;
        
    // Check if the first element is a peak
    if (arr[0] > arr[1])
        return 0;
        
    // Check if the last element is a peak
    if (arr[n - 1] > arr[n - 2])
        return n - 1;
    
    // Search Space for binary Search
    int lo = 1, hi = n - 2;
    
    while(lo <= hi) {
        int mid = lo + (hi - lo)/2;

        if(arr[mid] > arr[mid - 1] 
                       && arr[mid] > arr[mid + 1])
            return mid;
      
        if(arr[mid] < arr[mid + 1])
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    
    return 0;
}

/*
If an element is smaller than it's next element then it is guaranteed that at least one peak element will exist on the right side of this element.

Conversely if an element is smaller than it's previous element then it is guaranteed that at least one peak element will exist on the left side of this element.
*/

// Link: https://leetcode.com/problems/find-peak-element/description/