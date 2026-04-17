#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int atMostK(string& s, int k) {
        int ans = 0;
        vector<int> freq(26,0);
        int l = 0 ; // sliding window starting point
        int cnt = 0; // disctinct count at the current window
        
        for (int r = 0 ; r < s.length() ; r++){
            
            freq[ s[r] - 'a']++;
            
            if(freq[ s[r] - 'a'] == 1) cnt++;
            
            while(cnt > k){
                freq[s[l] - 'a']--;
                if(freq[s[l] - 'a'] == 0) cnt--;
                l++;
            }
            
            ans += r - l + 1;
        }
        
        return ans;
    }
    
    int countSubstr(string& s, int k) {
        // code here
        return atMostK(s, k) - atMostK(s, k - 1);
    }
};

// Link: https://www.geeksforgeeks.org/problems/count-number-of-substrings4528/1

/*
Time Complexity: O(n) for each call to atMostKDistinct.

Space Complexity: O(1) map size bounded by 26 characters for alphabets.
*/