#include<bits/stdc++.h>
using namespace std;

bool isSorted(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1]) 
            return false;
    }

    return true;  
}

/*
╭──────────────────────────────────────────────────────────────╮
│              Complexity                                      │
├──────────────────────────────────────────────────────────────┤
│  Time  : O(N)                                                │
│  Space : O(1)                                                │
│--------------------------------------------------------------│
│  Notes  : checks each adjacent pair once in a single pass    │
│           No extra data structure                            │
╰──────────────────────────────────────────────────────────────╯
*/