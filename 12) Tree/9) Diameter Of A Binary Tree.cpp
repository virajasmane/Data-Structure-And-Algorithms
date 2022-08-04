// Diameter of a B-Tree is the "No of nodes on the longest path b/w two leaf
// nodes"

// Example
//                                10
//                              /   \
//                            20*   60
//                          /   \
//                        30*   80*
//                       /  \     \
//                     40*  50    90*
//                    /            \
//                  60*            18*
//
// Count all the nodes with asterik the Diameter of this B-Tree is 7.




#include<bits/stdc++.h>
using namespace std;

struct Node
{
  int key;
  struct Node *left;
  struct Node *right;
  Node(int k){
      key=k;
      left=right=NULL;
  }
};

// Naive Solution.
// Find the left height of a node right height of a node and add 1 to it.

int height(Node *root)
{
  if(root == NULL)
    return 0;
  else
    return 1 + max( height(root->left), height(root->right) );
}

int Diameter(Node *root)
{
  if(root == NULL)
    return 0;

  int d1 = 1 + height(root->left) + height(root->right);

  int d2 = Diameter(root->left);

  int d3 = Diameter(root->right);

  return max({d1, d2, d3});
}
// Time Complexity :- 0(n^2)

// Think of a solution to solve it in O(n)

//______________________________________________________________________________

// Effecient Solution

// Precompute height of every node and store it in map.
// Requires O(n) Auxiliary space and also extra overhead for storing and look up
// of height for every node.

// Think of a solution that doesnt require the extra overhead.

//______________________________________________________________________________

// More Effecient Solution

// Modify the height funtion only.

// This function returns height but sets "result" variable to have diameter.
int result = 0;
int Modified_height(Node *root)
{
  if(root == NULL)
    return 0;

  int left_height = Modified_height(root->left);
  int right_height = Modified_height(root->right);

  result = max( result, 1 + left_height + right_height );

  return ( 1 + max(left_height, right_height) );
}
// Time Complexity :- O(n)
// Auxiliary Sapce :- O(h), same as the hash function.


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

  // cout<<Diameter(root);

  cout<<Modified_height(root)<<endl;
  cout<<result;

  return 0;
}
