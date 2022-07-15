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

Node *insert_begin(Node *head, int data)
{
  Node *temp = new Node(data);
  temp -> next = head;
  return temp;
}
// Time Complexity :- O(1)



Node *insert_end(Node *head, int data)
{
  Node *temp = new Node(data);

  if(head == NULL) // Explicitly handled null case here.
    return temp;

  Node *current = head;
  while(current -> next != NULL)
    current = current -> next;
  current -> next = temp;

  return head;
}
// Time Complexity :- 0(n), where n is the no of nodes.



Node *delete_head(Node *head)
{
  if(head == NULL)
    return NULL;
  else
  {
    Node *temp = head -> next;
    delete head;
    return temp;
  }
}
// Time Complexity :- O(1)


Node *delete_tail(Node *head)
{
  if(head == NULL) // Base case 1
    return NULL;

  if(head -> next == NULL) // Base case 2
  {
    delete head;
    return NULL;
  }

  Node *curr = head;
  while(curr -> next -> next != NULL)
    curr = curr -> next;

  delete (curr -> next);

  curr -> next = NULL;

  return head;
}
// Time Complexity :- 0(n), where n is the no of nodes.



Node *insert_at_position(Node *head, int position, int data)
{
  Node *temp = new Node(data);

  if(position == 1) // Corner case 1
  {
    temp -> next = head;
    return temp;
  }

  Node *current = head;
  for(int i=1; i<=position-2 && current != NULL; i++)
    current = current -> next;

  if(current == NULL) // Corner case 2
    return head;

  temp -> next = current -> next; // 🟢
  current -> next = temp; // 🔴
  // First do 🟢, not 🔴, because if we do 🔴 first we will lose the hold of the LL.

  return head;
}



int search_LL(Node *head, int x)
{
  int position = 1;

  while(head != NULL)
  {
    if(head -> data == x)
      return position;
    else
    {
      position++;
      head = head -> next;
    }
  }
  return -1;
}
// Time Complexity :- O(n), where n is the no of nodes.
// Auxiliary Space :- O(1)

int Recursive_search_LL(Node *head, int x)
{
  if(head == NULL)
    return -1;

  if(head -> data == x)
    return 1;
  else
  {
    int result = Recursive_search_LL(head -> next, x);
    if(result == -1)
      return -1;
    else
      return result+1;
  }
}
// Time Complexity :- O(n)
// Auxiliary Space :- O(n), where n is the no of nodes.


int main()
{
  Node *head = NULL;
  head = insert_begin(head, 30);
  head = insert_begin(head, 20);
  head = insert_begin(head, 10);

  head = insert_end(head, 40);
  head = insert_end(head, 50);

  head = delete_head(head);
  head = delete_tail(head);

  head = insert_at_position(head, 2, 25);

  cout<<search_LL(head, 25);
  cout<<endl;
  cout<<Recursive_search_LL(head, 25);

  cout<<endl;

  while(head != NULL)
  {
    cout<<(head -> data)<<" ";
    head = head -> next;
  }
  return 0;
}
