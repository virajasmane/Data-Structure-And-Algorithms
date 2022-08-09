// Assumed that all the keys(values) of BST are distinct.

// Operations of BST
// 1) Search
// 2) Insertion
// 3) Deletion
// 4) Floor Of A Given Key
// 5) Ceiling Of A Given Key

#include<bits/stdc++.h>
using namespace std;

struct Node
{
  int key;
  Node *left;
  Node *right;
  Node(int x)
  {
    key=x;
    left=right=NULL;
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





// 1) Search Operation

// Recursive Solution
// bool Search(Node *root, int x)
// {
//   if(root == NULL)
//     return false;
//   else if(root -> key == x)
//     return true;
//   else if(root -> key > x)
//     Search(root -> left, x);
//   else
//     Search(root -> right, x);
// }
// Time Complexity :- O(h), where h is the height of BST.
// Auxiliary Space :- O(h)

// Iterative Solution
bool Search(Node *root, int x)
{
  while(root != NULL)
  {
    if(root -> key == x)
      return true;
    else if(root -> key > x)
      root = root -> left;
    else
      root = root -> right;
  }
  return false;
}
// Time Complexity :- O(h), where h is the height of BST.
// Auxiliary Space :- O(1)

//______________________________________________________________________________

// 2) Insertion

// Recursive
// Node *insert(Node *root, int x)
// {
//   if(root == NULL)
//     return new Node(x);
//   else if(root -> key < x)
//     root -> right = insert(root -> right, x); // here root->right = is imp without that it wont work.
//   else if(root -> key > x)
//     root -> left = insert(root -> left, x); // here also root->left
//   return root;
// }
// Time Complexity :- O(h), where h is the height of BST.
// Auxiliary Space :- O(h)


// Iterative
Node *insert(Node *root, int x)
{
  Node *temp = new Node(x);
  Node *parent = NULL, *curr = root;

  while(curr != NULL)
  {
    parent = curr;
    if(curr -> key > x)
      curr = curr -> left;
    else if(curr -> key < x)
      curr = curr -> right;
    else
      return root;
  }

  if(parent == NULL)
    return temp;
  if(parent -> key > x)
    parent -> left = temp;
  else
    parent -> right = temp;

  return root;
}
// Time Complexity :- O(h), where h is the height of BST.
// Auxiliary Space :- O(1)

//______________________________________________________________________________

// 3) Deletion

Node *getSuccessor(Node *curr)
{
  curr = curr -> right;

  while(curr != NULL && curr -> left != NULL)
    curr = curr -> left;

  return curr;
}

Node *DelNode(Node *root, int x)
{
  if(root == NULL)
    return root;

  if(root -> key > x)
    root -> left = DelNode(root->left, x);
  else if(root -> key < x)
    root -> right = DelNode(root->right, x);
  else
  {
    if(root -> left == NULL)
    {
      Node *temp = root -> right;
      delete root;
      return temp;
    }
    else if(root -> right == NULL)
    {
      Node *temp = root -> left;
      delete root;
      return temp;
    }
    else
    {
      Node *succ = getSuccessor(root);
      root -> key = succ -> key;
      root -> right - DelNode(root -> right, succ -> key);
    }
  }

  return root;
}
// Time Complexity :- O(h), where h is the height of BST.
// Auxiliary Space :- O(h)

//______________________________________________________________________________

// 4) Floor Of A Given Key

Node *floor(Node *root, int x)
{
  Node *res = NULL;
  while(root != NULL)
  {
    if(root -> key == x)
      return root;
    else if(root -> key > x)
      root = root -> left;
    else
    {
      res = root;
      root = root -> right;
    }
  }

  return res;
}
// Time Complexity :- O(h), where h is the height of BST.
// Auxiliary Space :- O()

//______________________________________________________________________________

// 5) Ceiling Of A Given Key

Node *Ceiling(Node *root, int x)
{
  Node *res=NULL;
  while(root!=NULL)
  {
    if(root->key==x)
      return root;
    else if(root->key<x)
      root=root->right;
    else
    {
      res=root;
      root=root->left;
    }
  }
  return res;
}
// Time Complexity :- O(h), where h is the height of BST.
// Auxiliary Space :- O(1)








int main()
{
  Node *root = new Node(50);

  root -> left = new Node(30);
  root -> right = new Node(70);

  root -> left -> left = new Node(10);
  root -> left -> right = new Node(40);

  root -> right -> left = new Node(60);
  root -> right -> right = new Node(80);

  Search(root, 30) ? cout<<"True" : cout<<"False";
  cout<<endl;

  root = insert(root, 85);

  cout<<"Floor :- "<<(floor(root, 45) -> key);
  cout<<endl;

  cout<<"Ceiling :- "<<(Ceiling(root, 25) -> key);
  cout<<endl;

  inorder(root);

  return 0;
}
