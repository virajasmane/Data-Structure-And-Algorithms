// Children Sum Property.
// Sum of Children should be equal to the parent.

// Eg 1) This follows child sum Property
//                    20
//                  /   \
//                 8    12
//               /  \
//              3    5
//
// Eg 2) This follows child sum Property
//                    10
//                  /   \
//                 8     2
//                      /
//                     2
//
// Eg 3) This follows child sum Property
//                    5
//
// Eg 4) This doesn't follow child sum Property
//                    3
//                  /   \
//                 1     2
//                     /  \
//                    1    2
//

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


bool ChildSum(Node *root)
{
  if(root == NULL)
    return true;
  if(root->left == NULL && root->right == NULL)
    return true;

  int sum = 0;

  if(root->left != NULL)
    sum += root -> left -> key;

  if(root->right != NULL)
    sum += root -> right -> key;

  return( root->key == sum && ChildSum(root->left) && ChildSum(root->right) );
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

  cout<<ChildSum(root);

  return 0;
}
