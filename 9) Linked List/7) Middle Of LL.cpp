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

// Naive Solution

// void middle_of_LL(Node *head)
// {
//   if(head == NULL)
//   {
//     return ;
//     cout<<"1st case\n";
//   }
//
//   int count = 0;
//   Node *current = head;
//   while(current != NULL)
//   {
//     current = current -> next;
//     count++;
//   }
//
//   for(int i=0; i < count/2; i++)
//     head = head -> next;
//
//   cout<<"Middle Element is "<<(head -> data);
// }
// This solution does two traversal of the linked list. In effecient solution
// we expect one traversal of LL.

//______________________________________________________________________________

void middle_of_LL(Node *head)
{
  Node *slow = head, *fast = head;

  if(head == NULL)
    return ;

  while(fast != NULL && fast -> next != NULL)
  {
    slow = slow -> next;
    fast = fast -> next -> next;
  }
  cout<<"Middle Element is "<<(slow -> data);
}



int main()
{
  Node *head = new Node(10);
  head -> next = new Node(20);
  head -> next -> next = new Node(30);
  head -> next -> next -> next = new Node(40);

  middle_of_LL(head);
  cout<<endl;

  while(head != NULL)
  {
    cout<<(head -> data)<<" ";
    head = head -> next;
  }




  return 0;
}
