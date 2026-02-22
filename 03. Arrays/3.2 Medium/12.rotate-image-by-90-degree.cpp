#include <bits/stdc++.h>
using namespace std;

// degrees in clockwise direction
void rotate90(vector<vector<int>> &mat){ 
  	int n = mat.size();
  	
    // Perform Transpose
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            swap(mat[i][j], mat[j][i]);
        }
    }

    // Reverse each row
    for (int i = 0; i < n; i++)
        reverse(mat[i].begin(), mat[i].end());
}

/*
╭──────────────────────────────────────────────────────────────╮
│                        Complexity                            │
├──────────────────────────────────────────────────────────────┤
│  Time  : O(N²)                                               │
│  Space : O(1)                                                │
│--------------------------------------------------------------│
│  Note  : One full traversal for transpose                    │
│          One full traversal for row reversal                 │
│          No extra matrix used                                │
╰──────────────────────────────────────────────────────────────╯
*/

// Link: https://leetcode.com/problems/rotate-image/description/
