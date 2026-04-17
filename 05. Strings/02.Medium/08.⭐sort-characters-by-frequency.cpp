#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        vector<pair< char , int>> v(123);

        for(auto &i : s){
            int freq = v[i].second;
            v[i] = {i , freq + 1};
        }

        auto lambda = [&](pair<char, int> p1, pair<char, int> p2){
            return p1.second > p2.second;
        };

        sort(v.begin() , v.end() , lambda);

        string res;

        for(int i = 0 ; i < 123 ; i++){
            string temp = string(v[i].second , v[i].first);
            res += temp;

            if(v[i].second==0)break;
        } 

        return res;
    }
};

// Time Complexity: O(n + k log k), where n is the length of the string and k is the constant 123 for the alphabet and digits.

// Space Complexity: O(k) , where k is the constant 123 for the frequency array.

// Link: https://leetcode.com/problems/sort-characters-by-frequency/