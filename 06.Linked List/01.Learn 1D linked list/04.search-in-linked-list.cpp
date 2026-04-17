#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
  public:
    bool searchKey(Node* head, int key) {
        // Code here
        Node* temp = head;
        
        while(temp!= NULL){
            if(temp -> data == key) return true;
            temp = temp -> next;
        }
        
        return false;
    }
};


// Link: https://www.geeksforgeeks.org/problems/search-in-linked-list-1664434326/1

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/