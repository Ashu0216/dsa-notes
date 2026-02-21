#include <bits/stdc++.h>
using namespace std;

int findLargestElement(int arr[], int n) {
    int max = arr[0];  
    for (int i = 1; i < n; i++) {
        if (max < arr[i]) {  
            max = arr[i];
        }
    }

    return max;  
}

/*
╭──────────────────────────────────────╮
│              Complexity              │
├──────────────────────────────────────┤
│  Time  : O(N)                        │
│  Space : O(1)                        │
│--------------------------------------│
│  Notes  : Single pass traversal      │
│           No extra data structure    │
╰──────────────────────────────────────╯
*/