#include <iostream>
#include <vector>
using namespace std;

vector<int> spirallyTraverse(vector<vector<int>> &mat) {
    int m = mat.size();
    int n = mat[0].size();

    vector<int> res;

    // Initialize boundaries
    int top = 0, bottom = m - 1, left = 0, right = n - 1;

    // Iterate until all elements are stored
    while (top <= bottom && left <= right) {

        // store top row from left to right
        for (int i = left; i <= right; ++i) {
            res.push_back(mat[top][i]);
        }
        top++;

        // store right column from top to bottom
        for (int i = top; i <= bottom; ++i) {
            res.push_back(mat[i][right]);
        }
        right--;

        // store bottom row from right to left (if exists)
        if (top <= bottom) {
            for (int i = right; i >= left; --i) {
                res.push_back(mat[bottom][i]);
            }
            bottom--;
        }

        // store left column from bottom to top (if exists)
        if (left <= right) {
            for (int i = bottom; i >= top; --i) {
                res.push_back(mat[i][left]);
            }
            left++;
        }
    }
    return res;
}

/*
Algorithm:

1. Define the boundaries of the matrix with variables top, bottom, left, and right.
2. Print the top row from left to right and increment top.
3. Print the right column from top to bottom and decrement right.
4. Check if boundaries have crossed; if not, print the bottom row from right to left and decrement bottom.
5. Print the left column from bottom to top and increment left.
6. Repeat until all boundaries are crossed.
*/

/*
╭──────────────────────────────────────────────────────────────╮
│                        Complexity                            │
├──────────────────────────────────────────────────────────────┤
│  Time  : O(M × N)                                            │
│  Space : O(1)                                                │
│--------------------------------------------------------------│
│  Note  : Each element visited exactly once                   │
│          Only boundary variables used                        │
│          Output array not counted as extra space             │
╰──────────────────────────────────────────────────────────────╯
*/

// Link: https://leetcode.com/problems/spiral-matrix/description/