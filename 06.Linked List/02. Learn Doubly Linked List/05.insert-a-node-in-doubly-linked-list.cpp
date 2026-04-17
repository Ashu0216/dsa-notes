#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* next;
    Node* prev;

    Node(int x) {
        data = x;
        next = prev = nullptr;
    }
};

class Solution {
  public:
    Node *insertAtPos(Node *head, int p, int x) {
        // code here
        if(head == NULL) return head;
        
        int pos = 0;
        Node* temp = head;
        
        while(temp != NULL && pos <= p){
            if(pos == p){
                Node* newNode = new Node(x);
                newNode -> next = temp -> next;
                if(temp -> next) temp -> next -> prev = newNode;
                temp-> next = newNode;
                newNode -> prev = temp;
                break;
            }
            pos++;
            temp = temp -> next;
            
        }
        
        return head; 
        
    }
};

// LInk: https://www.geeksforgeeks.org/problems/insert-a-node-in-doubly-linked-list/1

/*
Time Complexity: O(n)
Space Complexity: O(1)  
*/