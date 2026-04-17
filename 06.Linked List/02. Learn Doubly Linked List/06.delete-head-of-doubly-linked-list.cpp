#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }

};

Node *deleteHead(Node *head) {
    // Your code here
    Node* temp = head;
    
    temp -> next -> prev = NULL;
    temp = temp -> next;
    head -> next = NULL;
    delete head;
    return temp;
    
    
}

// Link: https://www.geeksforgeeks.org/problems/delete-head-of-doubly-linked-list/1

/*
Time Complexity: O(1)
Space Complexity: O(1)  
*/