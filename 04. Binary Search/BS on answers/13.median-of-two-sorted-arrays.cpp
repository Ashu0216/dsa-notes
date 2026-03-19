#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int n1 = nums1.size();
        int n2 = nums2.size();

        if(n1 > n2) return findMedianSortedArrays(nums2 , nums1);

        int req = (n1 + n2 + 1)/2;

        int low = 0 , high = n1;

        while (low <= high){
            int mid = (low + high)/2;
            int mid2 = req - mid;

            int l1 = INT_MIN , l2 = INT_MIN;
            int r1 = INT_MAX , r2 = INT_MAX;

            if(mid > 0) l1 = nums1[mid - 1];
            if(mid2 > 0) l2 = nums2[mid2 - 1];
            if(mid < n1) r1 = nums1[mid];
            if(mid2 < n2) r2 = nums2[mid2];

            if( l1 <= r2 && l2 <= r1){
                if( (n1+n2) % 2 == 0){
                    return (long double)((max(l1 , l2) + min(r1 , r2))/2.0);
                }
                else{
                    return (long double)max(l1 , l2);
                }
            }

            if( l1 > r2) high = mid - 1;
            else low = mid + 1;
        }

        return -1;
        
    }
};

/*
Algorithm (Binary Search Partition):

1. Always binary search on the smaller array to keep complexity O(log(min(n1,n2))).
2. We partition both arrays such that:
      left_part_size = (n1 + n2 + 1) / 2
3. mid = elements taken from nums1
   mid2 = remaining elements taken from nums2.
4. Check correct partition condition:
      l1 <= r2  AND  l2 <= r1
   where:
      l1 = left of nums1 partition
      r1 = right of nums1 partition
      l2 = left of nums2 partition
      r2 = right of nums2 partition
5. If partition valid:
      - Odd length  -> median = max(l1, l2)
      - Even length -> median = (max(l1,l2) + min(r1,r2)) / 2
6. If l1 > r2 → move left in nums1
   else → move right in nums1.
*/

// Link: https://leetcode.com/problems/median-of-two-sorted-arrays/