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

void printCLL(Node *head)
{
  /*
  For loop method

  if(head == NULL)
    return ;

  cout<<head -> data<<" ";

  for(Node *p = head->next; p != head; p = p->next)
    cout<<p -> data<<" ";

  */

  // Do while loop method
  if(head == NULL)
    return ;

  Node *p = head;
  do
  {
    cout<<p -> data<<" ";
    p = p -> next;
  } while(p != head);
}






// Naive approach
// Node *insert_begin(Node *head, int x)
// {
//   Node *temp = new Node(x);
//
//   if(head == NULL)
//   {
//     temp -> next = temp;
//     return temp;
//   }
//   else
//   {
//     Node *current = head;
//
//     while(current -> next != head)
//       current = current -> next;
//
//     temp -> next = head;
//     current -> next = temp;
//
//     return temp;
//   }
// }
// Time Complexity :- O(n)

// Effecient Approach
// One way is to paas the tail also with the head then we wont have to travrse
// the LL to get the tail.

// There is anothe way to do it in O(1) time without passing the tail, it is mentioned below

// The Effecient approach is to insert the new element after the head and swap the head and the new element.

 Node *insert_begin(Node *head, int x)
 {
   Node *temp = new Node(x);
   if(head == NULL)
   {
     temp -> next = temp;
     return temp;
   }
   else
   {
     temp -> next = head -> next;// This and the next line is inserting new node b/w 1st and 2nd nodes.
     head -> next = temp;

     int temp_var = head -> data; // These 3 lines are swapping head and temp nodes;
     head -> data = temp -> data;
     temp -> data = temp_var;

     return head;
   }
 }
 // Time Complexity :- O(n)






// Naive Solution
// Node *insert_end(Node *head, int x)
// {
//   Node *temp = new Node(x);
//
//   if(head == NULL)
//   {
//     temp -> next = temp;
//     return temp;
//   }
//   else
//   {
//     Node *current = head;
//     while(current -> next != head)
//       current = current -> next;
//
//     current -> next = temp;
//     temp -> next = head;
//
//     return head;
//   }
// }
// Time Complexity :- O(n)

// Effecient Approach
// One way is to paas the tail also with the head then we wont have to travrse
// the LL to get the tail.

// There is anothe way to do it in O(1) time without passing the tail, it is mentioned below

// The Effecient approach is to insert the new element after the head and swap the head and the new element, and name the head as head, the swapped element becomes the last element.

Node *insert_end(Node *head, int x)
{
  Node *temp = new Node(x);
  if(head == NULL)
  {
    temp -> next = temp;
    return temp;
  }
  else
  {
    temp -> next = head -> next;
    head -> next = temp;

    int temp_var = head -> data;
    head -> data = temp -> data;
    temp -> data = temp_var;

    return temp;
  }
}
// Time Complexity :- O(1)





// Naive method
// Node *delete_head(Node *head)
// {
//   if(head == NULL)
//     return NULL;
//   if(head -> next == NULL)
//   {
//     delete head;
//     return NULL;
//   }
//   else
//   {
//     Node *current = head;
//     while (current -> next != head)
//       current = current -> next;
//
//     current -> next = head -> next;
//
//     delete head;
//
//     return (current -> next);
//   }
// }
// Time Complexity :- O(n), where n is no of nodes.
// Auxiliary Space :- O(1)

// Effecient Solution

// Copy the 2nd node to the head node and delete the 2nd node, now in 0(1) time we've deleted head node.
Node *delete_head(Node *head)
{
  if(head == NULL)
    return NULL;
  if(head -> next == head)
  {
    delete head;
    return NULL;
  }
  else
  {
    Node *current = head -> next;

    head -> data = head -> next -> data;

    head -> next = head -> next -> next;

    delete current;

    return head;
  }
}
// Time Complexity :- O(1)
// Auxiliary Space :- O(1)





Node *delete_kNode(Node *head, int k)
{
  if(head -> next == head)
  {
    delete head;
    return NULL;
  }
  if(k == 1)
  {
    delete_head(head);
  }
  else
  {
    Node *current = head;
    for(int i=0; i<k-2; i++)
      current = current -> next;

    Node *temp = current -> next;

    current -> next = current -> next -> next;

    delete temp;

    return head;
  }
}



int main()
{

  Node *head = new Node(10);
  head -> next = new Node(20);
  head -> next -> next = new Node(30);

  head -> next -> next -> next = head;

  head = insert_begin(head, 5);
  head = insert_end(head, 35);

  head = delete_head(head);
  head = delete_kNode(head, 3);

  printCLL(head);

  return 0;
}
