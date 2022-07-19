#include<bits/stdc++.h>
using namespace std;



struct Node
{
  int data;
  Node *next;
  Node(int x)
  {
    data = x;
    next = NULL;
  }
};

// Naive Solution
// Copy the Contents of the LL in an aux array and then copy them back in
// reverse order.

// Problems with this ?
// 1) Traverses the LL twice.
// 2) Uses Aux Space.
// 3) Data of LL could be string etc and copying it would be a costly operation.

Node *ReverseLL(Node *head)
{
  vector<int> arr;

  for(Node *curr=head; curr!=NULL; curr=curr->next)
    arr.push_back(curr -> data);

  for(Node *curr=head; curr!=NULL; curr=curr->next)
  {
    curr -> data = arr.back();
    arr.pop_back();
  }
  return head;
}
// Time Complexity :- O(n), where n is no of nodes
// Auxiliary Space :- O(n)

// _____________________________________________________________________________

Node *EReverseLL(Node *head)
{
  Node *curr = head, *prev = NULL;

  while(curr != NULL)
  {
    Node *next = curr -> next;
    curr -> next = prev;
    prev = curr;
    curr = next;
  }
  return prev; // prev is new head.
}
// Time Complexity :- O(n), where n is no of nodes
// Auxiliary Space :- O(1)



int main()
{
  Node *head = new Node(10);
  head -> next = new Node (20);
  head -> next -> next = new Node(30);
  head -> next -> next -> next = new Node(40);


  head = EReverseLL(head);

  while(head != NULL)
  {
    cout<<(head -> data)<<" ";
    head = head -> next;
  }

  return 0;
}
