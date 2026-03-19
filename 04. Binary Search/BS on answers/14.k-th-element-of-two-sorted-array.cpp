#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        // code here
        int n1 = a.size();
        int n2 = b.size();
        
        if(n2 < n1 ) return kthElement(b, a , k);
        
        int low = max(0 , k-n2);
        int high = min(k , n1);
        
        while(low <= high){
            int mid = (low + high)/2;
            
            int mid2 = k - mid;
            
            int l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MAX , r2 = INT_MAX;
            
            if(mid > 0 )l1 = a[mid - 1];
            if(mid2 > 0)l2 = b[mid2 - 1];
            if(mid < n1) r1= a[mid];
            if(mid2 < n2)r2 = b[mid2];
            
            if(l1 <= r2 && l2 <= r1){
                return max(l1 , l2);
            }
            
            if( l1 > r2) high = mid - 1;
            else low = mid + 1;
        }
        
        return -1;
        
    }
};

/*
Algorithm: K-th Element of Two Sorted Arrays (Binary Search Partition)

1. Always perform binary search on the smaller array to keep complexity O(log(min(n1,n2))).

2. We divide the arrays such that the left side contains exactly k elements.
      mid  = elements taken from array a
      mid2 = k - mid elements taken from array b

3. Valid search range:
      low  = max(0, k - n2)   -> ensures mid2 ≤ n2
      high = min(k, n1)       -> ensures mid ≤ n1

4. For each partition compute boundary elements:
      l1 = last element of left part of a
      r1 = first element of right part of a
      l2 = last element of left part of b
      r2 = first element of right part of b

5. Correct partition condition:
      l1 ≤ r2  AND  l2 ≤ r1

6. If partition is valid:
      k-th element = max(l1, l2)

7. If l1 > r2 → move left in a (high = mid - 1)
   else       → move right in a (low = mid + 1)

Time Complexity: O(log(min(n1, n2)))
Space Complexity: O(1)
*/

// Link: https://www.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1