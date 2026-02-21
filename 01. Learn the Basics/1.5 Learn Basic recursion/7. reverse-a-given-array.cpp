#include <bits/stdc++.h>
using namespace std;

// Two-pointer approach
class SolutionTwoPointer {
public:
    void reverseArray(vector<int>& arr) {
        int left = 0;
        int right = arr.size() - 1;

        while (left < right) {
            swap(arr[left++], arr[right--]);
        }
    }
};

// STL approach
class SolutionSTL {
public:
    void reverseArray(vector<int>& arr) {
        reverse(arr.begin(), arr.end());
    }
};

/*
╭─────────────────────────────────────────────────────────────╮
│                         Complexity                          │
├─────────────────────────────────────────────────────────────┤
│  Two-Pointer                                                │
│  Time  : O(N)                                               │
│  Space : O(1)                                               │
│-------------------------------------------------------------│
│  STL reverse()                                              │
│  Time  : O(N)                                               │
│  Space : O(1)                                               │
│-------------------------------------------------------------│
│  Notes : Both reverse in-place                              │
│          STL internally uses similar logic                  │
╰─────────────────────────────────────────────────────────────╯
*/