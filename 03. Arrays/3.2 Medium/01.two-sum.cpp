
// Approach 1: Using Hash Set - O(n) time and O(n) space
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

bool twoSum(vector<int> &arr, int target){
  
    // Create an unordered_set to store the elements
    unordered_set<int> s;

    for (int i = 0; i < arr.size(); i++){

        // Calculate the complement that added to
        // arr[i], equals the target
        int complement = target - arr[i];

        // Check if the complement exists in the set
        if (s.find(complement) != s.end())
            return true;

        // Add the current element to the set
        s.insert(arr[i]);
    }
  
    // If no pair is found
    return false;
}

/*
╭──────────────────────────────────────────────────────────────╮
│              Complexity                                      │
├──────────────────────────────────────────────────────────────┤
│  Time  : O(N) (average case)                                 │
│  Space : O(N)                                                │
│--------------------------------------------------------------│
│  Notes  : Single traversal of array                          │
│           Unordered set stores elements                      │
╰──────────────────────────────────────────────────────────────╯
*/

//  Approach 2:  Sorting and Two-Pointer Technique - O(n × log(n)) time and O(1) space

bool twoSum(vector<int> &arr, int target){
  
    sort(arr.begin(), arr.end());

    int left = 0, right = arr.size() - 1;

    // Iterate while left pointer 
    // is less than right
    while (left < right){
        int sum = arr[left] + arr[right];

        // Check if the sum matches the target
        if (sum == target)
            return true;
        else if (sum < target)
        
        // Move left pointer to the right
            left++; 
        else
        
        // Move right pointer to the left
            right--; 
    }
    // If no pair is found
    return false;
}

/*
╭──────────────────────────────────────────────────────────────╮
│                        Complexity                            │
├──────────────────────────────────────────────────────────────┤
│  Time  : O(N log N)                                          │
│  Space : O(N)                                                │
│--------------------------------------------------------------│
│  Notes : Sorting takes O(N log N)                            │
│          Two-pointer scan is O(N)                            │
│          Extra array stores values with indices              │
╰──────────────────────────────────────────────────────────────╯
*/

// Link: https://leetcode.com/problems/two-sum/description/