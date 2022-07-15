#include <bits/stdc++.h>
using namespace std;

// The function for creating LL
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



// Traversing the Singly LL
void Printlist(Node *head)
{
  Node *current = head;
  while(current != NULL)
  {
    cout<<(current -> data)<<" ";
    current = current -> next;
  }
}
// Time Complexity :- O(n), where n is no of nodes.
// Auxiliary Space :- O(1)
// Can also be traversed like this.
// void Printlist(Node *head) // By changing the head here only the OG head in the int main() wont change because both are different. To check this print head twice in int main()
// {
//   while(head != NULL)
//   {
//     cout<<(head -> data)<<" ";
//     head = head -> next;
//   }
// }


// Traversing the Singly LL Recursively
void R_Printlist(Node *head)
{
  if(head == NULL)
    return;
  cout<<(head -> data)<<" ";
  Printlist(head -> next);
}
// Time Complexity :- O(n)
// Auxiliary Space :- O(n), where n is no of nodes.
// So iterative is better.





int main()
{
  Node *head = new Node(10); // This line for creating individual node.
  head -> next = new Node(20); // This and the next 2 lines for creating and linking the next nodes
  head -> next -> next = new Node(30);
  head -> next -> next -> next = new Node(40);
  R_Printlist(head);



  return 0;
}
