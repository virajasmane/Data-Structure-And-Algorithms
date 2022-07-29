// Link for the problem
// https://practice.geeksforgeeks.org/tracks/DSASP-Tree/?batchId=154&tab=2

// Check for height balanced tree.
// Difference b/w heights of left subtree and right subtree should not be more
// than 1, and this should be true for every node.

// Eg 1)
//                    20
//                  /   \
//                 8    12
//                     /  \
//                    3    5
// O/P :- YES

// Eg 2)
//                    10
//                      \
//                       2
//                        \
//                         2
// O/P :- NO

// Eg 4)
//                    00003
//                  /      \
//                 1        2
//               /  \      /
//              5    9    2
//                 /  \
//               20   12
// O/P :- YES

// Eg 4)
//                    03
//                  /   \
//                 1     2
//               /  \     \
//              5    9     2
//                        /
//                      12
// O/P :- NO

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

int height(Node *root)
{
  if(root == NULL)
    return 0;
  else
    return ( max( height(root->left), height(root->right) ) + 1 );
}

// Naive Solution

// Each node is traversed once so its time Complexityis O(n) and at every
// traversal it finds the height of its subtrees, so it does O(n) work for Each
// node thus making Time Complexity O(n^2).

bool isBalanced(Node *root)
{
  if(root == NULL)
    return true;

  int left_height = height(root->left);
  int right_height = height(root->right);

  return ( abs(left_height-right_height) <= 1 && isBalanced(root->left) && isBalanced(root->right) );
}
// Time Complexity :- O(n^2), where n is no of nodes.

//______________________________________________________________________________

// Effecient Solution.

// In this implementation we traverse the node once only and in that traversal
// only we find if tree is balanced and the height.
// Note only one var is used for both imp things(unbalanced tree and height),
// if tree is unbalanced var will return -1, if balanced then it'll return
// the height.
// The return type here is int not bool note that.

int isBalancedE(Node *root)
{
  if(root == NULL)
    return 0;

  int left_height = isBalancedE(root -> left); // check if left subtree is balanced or not also get it's height.
  if(left_height == -1)
    return -1;

  int right_height = isBalancedE(root -> right); // check if the right subtree is balanced or not also get it's height.
  if(right_height == -1)
    return -1;

  if(abs(left_height-right_height) > 1)
    return -1;
  else
    return max(left_height, right_height) + 1;
}
// Time Complexity :- O(n)


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

  // cout<<isBalanced(root);

  cout<<isBalancedE(root);

  return 0;
}
