#include <bits/stdc++.h>
using namespace std;

void frequency(int arr[], int n) {
    unordered_map<int, int> freq;

    for (int i = 0; i < n; i++)
        freq[arr[i]]++;

    for (const auto& p : freq)
        cout << p.first << " " << p.second << "\n";
}

/*
╭──────────────────────────────────────────────────────────────╮
│                         Complexity                           │
├──────────────────────────────────────────────────────────────┤
│  Time  : O(N)  (average case)                                │
│  Space : O(N)                                                │
│--------------------------------------------------------------│
│  Notes : Unordered_map operations are O(1) average           │
│          Worst case can degrade to O(N^2)                    │
╰──────────────────────────────────────────────────────────────╯
*/