#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reverseArray(vector<int>& arr) {
        int p1 = 0;
        int p2 = arr.size() - 1;

        while (p1 < p2) {
            swap(arr[p1], arr[p2]);
            p1++;
            p2--;
        }
    }
};

//Use STL reverse to reverse array in-place
class Solution {
public:
    void reverseArray(vector<int>& arr) {
        
        reverse(arr.begin(), arr.end());
    }
};