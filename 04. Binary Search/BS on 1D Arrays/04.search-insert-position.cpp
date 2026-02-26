#include <iostream>
#include <vector>
using namespace std;

int searchInsertK(vector<int> arr, int k) {  
    int left = 0, right = arr.size() - 1;  
    while(left <= right) {  
        int mid = left + (right - left) / 2;  
        
        // if k is found at mid
        if(arr[mid] == k) {  
            return mid;  
        }  
        // if k is smaller, search in left half
        else if(arr[mid] > k) {  
            right = mid - 1;  
        }  
        // if k is larger, search in right half
        else {  
            left = mid + 1;  
        }  
    }  

    // if k is not found, return insert position
    return left;  
}

// O(log n) Time and O(1) Space

// Link: https://leetcode.com/problems/search-insert-position/description/