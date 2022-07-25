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

void inorder(Node *root)
{
  if(root != NULL)
  {
    inorder(root -> left);
    cout<<(root -> key)<<" ";
    inorder(root -> right);
  }
}
// Time Complexity :- 0(n), where n is no of nodes.
// Auxiliary Space :- 0(h), where h is height of the tree.



void preorder(Node *root)
{
  if (root != NULL)
  {
    cout<<(root -> key)<<" ";
    preorder(root -> left);
    preorder(root -> right);
  }
}
// Time Complexity :- 0(n), where n is no of nodes.
// Auxiliary Space :- 0(h), where h is height of the tree.



void postorder(Node *root)
{
  if(root != NULL)
  {
    postorder(root -> left);
    postorder(root -> right);
    cout<<(root -> key)<<" ";
  }
}
// Time Complexity :- 0(n), where n is no of nodes.
// Auxiliary Space :- 0(h), where h is height of the tree.



int height(Node *root)
{
  if(root == NULL)
    return 0;
  else
    return ( max( height(root->left), height(root->right) ) + 1 );
}
// Time Complexity :- 0(n), where n is no of nodes.
// Auxiliary Space :- 0(h), where h is height of the tree.



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

  cout<<"Inorder Traversal :- ";
  inorder(root);
  cout<<endl;
  cout<<endl;

  cout<<"Preorder Traversal :- ";
  preorder(root);
  cout<<endl;
  cout<<endl;

  cout<<"Postorder Traversal :- ";
  postorder(root);
  cout<<endl;
  cout<<endl;

  cout<<"Height :- "<<height(root);
  cout<<endl;

  return 0;
}
