
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


int maxWidth(Node *root)
{
  if(root == NULL)
    return 0;

  if(root->left == NULL && root->right == NULL)
    return 1;
  else
    return maxWidth(root -> left) + maxWidth(root -> right);
}
// Time Complexity :- O(n), where n is no of nodes.
// Auxiliary Space :- O(h), where h is the height of the tree.

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

  cout<<maxWidth(root);

  return 0;
}
