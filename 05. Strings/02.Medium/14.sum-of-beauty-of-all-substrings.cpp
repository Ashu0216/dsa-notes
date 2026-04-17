#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int beautySum(string s) {

        int sum = 0;
        int n = s.size();

        for(int i =0 ; i < n ; i++){
            int freq[26] = {0};

            for(int j = i ; j < n ; j++){

                freq[s[j] - 'a']++;

                int maxf = 0 , minf = INT_MAX;

                for(int f: freq){
                    if(f > 0 ){
                        maxf = max(maxf , f);
                        minf = min(minf , f);
                    }
                }

                sum += (maxf - minf);
            }
        }

        return sum;
        
    }
};

/*
Time complexity:
O(n^2)
Two nested loops give (O(n^2)), and checking frequencies takes constant time (O(26)).

Space complexity:
O(1)
The frequency array is of fixed size (26).
*/

// Link: https://leetcode.com/problems/sum-of-beauty-of-all-substrings/