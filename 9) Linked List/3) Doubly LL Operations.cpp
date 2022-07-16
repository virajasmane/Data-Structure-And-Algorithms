#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  Node *next;
  Node *prev;
  Node(int x)
  {
    data = x;
    next = prev = NULL;
  }
};

Node *insert_begin(Node *head, int x)
{
  Node *temp = new Node(x);
  temp -> next = head;
  if(head != NULL)
    head -> prev = temp;

  return temp;
}

Node *insert_end(Node *head, int x)
{
  Node *temp = new Node(x);

  if(head == NULL) // Base case
    return temp;

  Node *current = head;
  while(current -> next != NULL)
    current = current -> next;
  current -> next = temp;
  temp -> prev = current;

  return head;
}



Node *reverseDLL(Node *head)
{
  if(head == NULL || head -> next == NULL)
    return head;

  Node *temp = NULL;
  Node *current = head;

  while(current != NULL)
  {
    temp = current -> prev; // Swapping
    current -> prev = current -> next; // Swapping
    current -> next = temp; // Swapping

    current = current -> prev; // Taking the loop forward, here its prev not next because remember we have swapped next and prev in the above 3 lines.
  }
  return temp -> prev;
}
// Time Complexity :- O(n), where n is no of nodes.
// Auxiliary Space :- O(1)




Node *delete_head(Node *head)
{
  if(head == NULL) // Base case 1, 0 nodes
    return NULL;

  if(head -> next == NULL) // Base case 2, 1 node
  {
    delete head;
    return NULL;
  }
  else
  {
    Node *current = head;
    current = current -> next;

    current -> prev = NULL;

    delete head;

    return current;
  }
}
// Time Complexity :- O(1)
// Auxiliary Space :- O(1)




Node *delete_tail(Node *head)
{
  if(head == NULL)
    return NULL;

  if(head -> next == NULL)
  {
    delete head;
    return NULL;
  }
  else
  {
    Node *current = head;
    while(head -> next != NULL)
      head = head -> next;

    head -> prev -> next = NULL;

    delete head;

    return current;
  }
}
// Time Complexity :- O(n), where n is no of nodes || This can be reduced to O(1) by passing tail pointer as an argument in the function.
// Auxiliary Space :- O(1)




int main()
{
  Node *head = new Node(10);
  Node *temp1 = new Node(20);
  Node *temp2 = new Node(30);

  head -> next = temp1;
  temp1 -> prev = head;

  temp1 -> next = temp2;
  temp2 -> prev = temp1;

  head = insert_begin(head, 5);
  head = insert_end(head, 35);

  head = reverseDLL(head);

  head = delete_head(head);
  head = delete_tail(head);

  while(head != NULL)
  {
    cout<<(head -> data)<<" ";
    head = head -> next;
  }
  return 0;
}
