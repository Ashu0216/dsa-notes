#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

vector<int> generateRow(int row){
    int ans = 1;
    vector<int> ansRow;

    ansRow.push_back(1);

    for (int col = 1; col < row ; col++){
        ans = ans * (row-col);
        ans = ans / col;
        ansRow.push_back(ans);
    }
    return ansRow;
}
    vector<vector<int>> generate(int numRows) {

        vector<vector<int>> ans;

        for (int i = 1 ; i <= numRows ; i++){
            ans.push_back((generateRow(i)));
        }

        return ans;
        
    }
};

/*
╭──────────────────────────────────────────────────────────────╮
│                        Complexity                            │
├──────────────────────────────────────────────────────────────┤
│  Time  : O(N²)                                               │
│  Space : O(N²)                                               │
│--------------------------------------------------------------│
│  Note  : For N rows, total elements generated ≈ N(N+1)/2     │
│          Each row built in linear time                       │
│          Output matrix stores all elements                   │
╰──────────────────────────────────────────────────────────────╯
*/

long long findPascalElement(int r, int c) {
        // Element is C(r-1, c-1)
        int n = r - 1;
        int k = c - 1;

        long long result = 1;

        // Compute C(n, k) using iterative formula
        for (int i = 0; i < k; i++) {
            result *= (n - i);
            result /= (i + 1);
        }

        return result;
    }

/*
╭──────────────────────────────────────────────────────────────╮
│                        Complexity                            │
├──────────────────────────────────────────────────────────────┤
│  Time  : O(min(C, R − C))                                    │
│  Space : O(1)                                                │
│--------------------------------------------------------------│
│  Note  : Uses symmetry of binomial coefficient               │
│          Iterative computation without extra storage         │
╰──────────────────────────────────────────────────────────────╯
*/

// Link: https://leetcode.com/problems/pascals-triangle/
