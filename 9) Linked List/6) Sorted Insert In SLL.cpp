#include <bits/stdc++.h>
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


Node *sorted_insert(Node *head, int x)
{
  Node *temp = new Node(x);
  if(head == NULL)
    return temp;
  if(x < head -> data)
  {
    temp -> next = head;
    return temp;
  }

  Node *current = head;
  while(current -> next != NULL && current -> next -> data < x)
    current = current -> next;

  temp -> next = current -> next;
  current -> next = temp;

  return head;
}
// Time Complexity :- 0(position)
// Auxiliary Space :- O(1)



int main()
{
  Node *head = new Node(10);
  head -> next = new Node(20);
  head -> next -> next = new Node(30);

  head = sorted_insert(head, 35);

  while(head != NULL)
  {
    cout<<(head -> data)<<" ";
    head = head -> next;
  }

  return 0;
}
