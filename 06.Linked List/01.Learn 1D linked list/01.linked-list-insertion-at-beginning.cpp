#include<bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


class Solution {
  public:
    Node *insertAtFront(Node *head, int x) {
        // Code here
        Node* newNode = new Node(x);
        newNode -> next = head;
        return newNode;
        
    }
};

//link: https://www.geeksforgeeks.org/problems/linked-list-insertion-at-beginning/1

/*
Time Complexity: O(1)
Space Complexity: O(1)
*/
