#include <iostream>
#include <vector>
using namespace std;

void setMatrixZeroes(vector<vector<int>> &mat) {
    int n = mat.size(), m = mat[0].size();

    int c0 = 1;

    // Traverse the arr and mark first 
    // cell of each row and column
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 0) {

                // mark i-th row
                mat[i][0] = 0;

                // mark j-th column
                if (j == 0)
                    c0 = 0;
                else
                    mat[0][j] = 0;
            }
        }
    }

    // Traverse and mark the matrix from 
    // (1, 1) to (n - 1, m - 1)
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {

            // Check for col & row
            if (mat[i][0] == 0 || mat[0][j] == 0) {
                mat[i][j] = 0;
            }
        }
    }

    // Mark the first row
    if (mat[0][0] == 0) {
        for (int j = 0; j < m; j++)
            mat[0][j] = 0;
    }
  
    // Mark the first column
    if (c0 == 0) {
        for (int i = 0; i < n; i++)
            mat[i][0] = 0;
    }
}



/*
╭──────────────────────────────────────────────────────────────╮
│                       Algorithm                              │
├──────────────────────────────────────────────────────────────┤
│  1. Check if first row has any 0 → store in firstRowZero     │
│  2. Check if first column has any 0 → store in firstColZero  │
│  3. Traverse matrix (excluding first row/col):               │
│       - If mat[i][j] == 0                                    │
│         → mark row using mat[i][0] = 0                       │
│         → mark col using mat[0][j] = 0                       │
│  4. Traverse again (excluding first row/col):                │
│       - If row or column marker is 0 → set cell to 0         │
│  5. Finally, zero first row/column based on stored flags     │
│                                                              │
│  Idea : First row & column act as in-place markers           │
╰──────────────────────────────────────────────────────────────╯
*/

/*
╭──────────────────────────────────────────────────────────────╮
│                        Complexity                            │
├──────────────────────────────────────────────────────────────┤
│  Time  : O(M × N)                                            │
│  Space : O(1)                                                │
│--------------------------------------------------------------│
│  Note  : Matrix reused for markers                           │
│          Only two boolean flags used                         │
│          Constant number of full matrix passes               │
╰──────────────────────────────────────────────────────────────╯
*/

// Link: https://leetcode.com/problems/set-matrix-zeroes/description/