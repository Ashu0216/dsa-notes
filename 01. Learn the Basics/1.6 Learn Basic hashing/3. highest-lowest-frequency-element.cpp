#include <bits/stdc++.h>
using namespace std;

class FrequencyCounter {
public:
    void Frequency(int arr[], int n)
    {
        unordered_map<int, int> map; 

        for (int i = 0; i < n; i++)
            map[arr[i]]++;

        int maxFreq = 0, minFreq = n;
        int maxEle = 0, minEle = 0;

        for (auto it : map) {
            int element = it.first;
            int count = it.second;

            if (count > maxFreq) {
                maxFreq = count;
                maxEle = element;
            }

            if (count < minFreq) {
                minFreq = count;
                minEle = element;
            }
        }

        // Print results
        cout << "The highest frequency element is: " << maxEle << "\n";
        cout << "The lowest frequency element is: " << minEle << "\n";
    }
};

/*
╭──────────────────────────────────────────────────────────────╮
│                         Complexity                           │
├──────────────────────────────────────────────────────────────┤
│  Time  : O(N)  (average case)                                │
│  Space : O(N)                                                │
│--------------------------------------------------------------│
│  Notes : Two passes — build map and scan map                 │
│          Unordered_map is O(1) average per operation         │
│          Worst case can degrade to O(N^2)                    │
╰──────────────────────────────────────────────────────────────╯
*/