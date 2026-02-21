#include <bits/stdc++.h>
using namespace std;

void Frequency(int arr[], int n) {

    unordered_map<int, int> map;

    for (int i = 0; i < n; i++) {
        map[arr[i]]++;
    }

    for (auto x : map) {
        cout << x.first << " " << x.second << endl;
    }
}
