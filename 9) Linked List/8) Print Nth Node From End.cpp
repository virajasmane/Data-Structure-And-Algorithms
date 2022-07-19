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

// Method 1, by finding the length of the LL.
// void Find_NthNode(Node * head, int n)
// {
//   int length = 0;
//   Node *current = head;
//   while(current != NULL)
//   {
//     current = current -> next;
//     length++;
//   }
//
//   if(length < n) // Corner case
//     return ;
//
//   for(int i=0; i<length-n; i++)
//     head = head -> next;
//
//   cout<<(head -> data)<<endl;
// }

//______________________________________________________________________________

// Method 2, both the methods have same TC just different approach.
// Use two pointer tehchnique
// 1) Move "first" n positions ahead.
// 2) Start "second" pointer from head.
// 3) Move both "first" and "second" at the same speed, When "first
//    reaches NULL, second reaches required node;

void Find_NthNode(Node * head, int n)
{
  Node *first = head, *second = head;
  for(int i=0; i<n ; i++)
  {
    if(first == NULL) // If n is more than the length of the LL.
      return ;
    first = first -> next;
  }
  while(first != NULL)
  {
    first = first -> next;
    second = second -> next;
  }
  cout<<(second -> data)<<endl;
}



int main()
{
  Node *head = new Node(10);
  head -> next = new Node(20);
  head -> next -> next = new Node(30);
  head -> next -> next -> next = new Node(40);

  Find_NthNode(head, 2);

  while(head != NULL)
  {
    cout<<(head -> data)<<" ";
    head = head -> next;
  }

  return 0;
}
