#include <bits/stdc++.h>
using namespace std;

// Definition for Linked List
class Node
{
public:
  int data;
  Node *next;

  Node(int x)
  {
    data = x;
    next = NULL;
  }
};

class Solution
{
public:
  int getCount(Node *head)
  {
    // Code here
    int cnt = 0;

    Node *temp = head;

    while (temp != NULL)
    {
      cnt++;
      temp = temp->next;
    }

    return cnt;
  }
};

// Link: https://www.geeksforgeeks.org/problems/count-nodes-of-linked-list/1

/*

Time Complexity: O(n)
Space Complexity: O(1)

*/