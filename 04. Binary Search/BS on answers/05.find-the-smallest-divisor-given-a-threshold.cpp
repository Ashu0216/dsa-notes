#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long int sumOfDividends(vector<int>& nums , int mid){
        long int sum = 0;

        for (int i = 0 ; i < nums.size() ; i++){
            sum += ceil((double)nums[i] / (double)mid);
        }

        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin() , nums.end());

        while(low <= high){
            int mid = (low + high )/2;

            int sum = sumOfDividends(nums, mid);

            if( sum <= threshold){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return low;
    }
};

// Time Complexity:O(log(max(arr[]))*N), where max(arr[]) = maximum element in the array, N = size of the array. We are applying binary search on our answers that are in the range of [1, max(arr[])]. For every possible divisor ‘mid’, we call the sumByD() function. Inside that function, we are traversing the entire array, which results in O(N).

// Link: https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/