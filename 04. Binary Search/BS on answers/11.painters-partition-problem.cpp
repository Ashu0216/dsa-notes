#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int calculateTime(vector<int>& arr , int k , int mid){
        int currTime = arr[0];
        int painters = 1;
        
        for(int i = 1 ; i < arr.size() ; i++){
            if( currTime + arr[i] <= mid){
                currTime += arr[i];
            }
            else{
                painters++;
                currTime = arr[i];
            }
        }
        
        return painters;
    }
    int minTime(vector<int>& arr, int k) {

        int low = *max_element(arr.begin() , arr.end());
        int high = 0;
        
        for (int i = 0 ; i < arr.size() ; i++){
            high += arr[i];
        }
        
        if(k > arr.size()) return low;
        
        while (low <= high){
            int mid = (low + high)/2;
            
            int painters = calculateTime(arr , k , mid);
            
            if(painters > k){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        
        return low;
    }
};

/*
Time Complexity: O(N * log(sum(arr[])-max(arr[])+1)), where N = size of the array, sum(arr[]) = sum of all array elements, max(arr[]) = maximum of all array elements.
Space Complexity: O(1) since no extra space is required.
*/

// Link: https://www.geeksforgeeks.org/problems/the-painters-partition-problem1535/1