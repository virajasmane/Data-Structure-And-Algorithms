#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  Node *prev;
  Node *next;
  Node(int x)
  {
    data = x;
    prev = NULL;
    next = NULL;
  }
};


void printCLL(Node *head)
{
  if(head == NULL)
    return ;

  Node *p = head;
  do
  {
    cout<<(p -> data)<<" ";
    p = p -> next;
  } while(p != head);
}




Node *insert_begin(Node *head, int x)
{
  Node *temp = new Node(x);

  if(head == NULL)
  {
    temp -> next = temp;
    temp -> prev = temp;
    return temp;
  }
  head -> prev -> next = temp;
  temp -> prev = head -> prev;

  temp -> next = head;
  head -> prev = temp;

  return temp;
}


Node *insert_end(Node *head, int x)
{
  // Full same as insert_begin function just at the last line where there
  // is "return temp", put there "return head", and it will become insert_end function.

  Node *temp = new Node(x);

  if(head == NULL)
  {
    temp -> next = temp;
    temp -> prev = temp;
    return temp;
  }
  head -> prev -> next = temp;
  temp -> prev = head -> prev;

  temp -> next = head;
  head -> prev = temp;

  return head; // change is here from insert_begin funtion.
}



int main()
{
  Node *head = new Node(10);
  Node *temp1 = new Node(20);
  Node *temp2 = new Node(30);

  head -> next = temp1;
  temp1 -> prev = head;

  temp1 -> next = temp2;
  temp2 -> prev = temp1;

  temp2 -> next = head;
  head -> prev = temp2;

  head = insert_begin(head, 5);

  head = insert_end(head, 35);


  printCLL(head);
}
