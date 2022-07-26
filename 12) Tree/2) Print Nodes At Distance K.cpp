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

void Print_k_dist(Node *root, int k)
{
  if(root == NULL)
    return;

  if(k == 0)
    cout<<(root -> key)<<" ";
  else
  {
    Print_k_dist(root -> left, k-1);
    Print_k_dist(root -> right, k-1);
  }
}
// Time Complexity :- O(n), where n is no of nodes.
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

  Print_k_dist(root, 1);

  return 0;
}
