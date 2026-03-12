#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
    bool allocateBooks( vector<int>& arr , int k , int mid){
        int students = 1;
        int currPages = 0;
        
        for(int i = 0 ; i < arr.size() ; i++){
            if(arr[i] >  mid) return false;
            
            if(currPages + arr[i] <= mid){
                currPages += arr[i];
            }
            else{
                students++;
                currPages = arr[i];
            }
        }
        
        return students <= k;
    }
    int findPages(vector<int> &arr, int k) {

        // k = students
        // arr[i] = pages in ith book
        // each student should get minimum one book and should be allocated contiguous books.
        // minimize pages
        
        if (k > arr.size()) return -1;
        
        int low = *max_element(arr.begin() , arr.end());
        
        int high = 0;
        
        for(int i = 0  ;  i < arr.size() ; i++)
            high += arr[i];
            
            
        while (low <= high){
            int mid = (low + high) / 2;
            
            bool possible = allocateBooks(arr , k , mid);
            
            if(possible){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        
        return low;
        
    }
};

/*
Time Complexity: O(N * log(sum(arr[])-max(arr[])+1)), where N = size of the array, sum(arr[]) = sum of all array elements, max(arr[]) = maximum of all array elements.

Space Complexity:  O(1) as we are not using any extra space to solve this problem.
*/

// Link: https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1