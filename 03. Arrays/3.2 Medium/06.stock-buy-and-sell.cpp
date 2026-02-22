#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int stockbuySell(vector<int>& prices) {

        int minPrice = INT_MAX;
        int maxProfit = 0;

        for (int price : prices) {
            if (price < minPrice) {
                minPrice = price;
            }
           
            else {
                maxProfit = max(maxProfit, price - minPrice);
            }
        }

        return maxProfit;
    }
};


// If current price is less than minPrice, update minPrice
// Else calculate profit and update maxProfit if it's greater

/*
╭──────────────────────────────────────────────────────────────╮
│              Complexity                                      │
├──────────────────────────────────────────────────────────────┤
│  Time  : O(N)                                                │
│  Space : O(1)                                                │
│--------------------------------------------------------------│
│  Notes  : We traverse the entire original array only once    │
│           No extra data structure                            │
╰──────────────────────────────────────────────────────────────╯
*/
