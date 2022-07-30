// Convert B-tree to DLL without using extra space ie use the same memory
// B-Tree.
// The DLL should be in preorder form.
// So we'll convert left as prev and right as next.
#include<bits/stdc++.h>
using namespace std;

struct Node
{
  int key;
  Node *left;
  Node *right;
  Node(int x)
  {
    key = x;
    left = right = NULL;
  }
};


void PrintList(Node *head)
{
  Node *current = head;
  while(current != NULL)
  {
    cout<<(current -> key)<<" ";
    current = current -> right;
  }
}



Node *BTToDLL(Node *root)
{
  if(root == NULL)
    return root;

  static Node *prev = NULL;
  Node *head = BTToDLL(root->left);

  if(prev == NULL)
    head = root;
  else
  {
    root -> left = prev;
    prev -> right = root;
  }
  prev = root;

  BTToDLL(root->right);

  return head;
}
// Time Complexity :- O(n), where n is no of nodes
// Auxiliary Space :- O(h), where h is height of the tree.

int main()
{
  Node *root = new Node(10);

  root -> left = new Node(20);
  root -> right = new Node(30);

  root -> left -> left = new Node(40);
  root -> left -> right = new Node(50);
  root -> right -> right = new Node(60);

  root -> left -> right -> left = new Node(70);
  root -> left -> right -> right = new Node(80);

  root = BTToDLL(root);

  PrintList(root);


  return 0;
}
