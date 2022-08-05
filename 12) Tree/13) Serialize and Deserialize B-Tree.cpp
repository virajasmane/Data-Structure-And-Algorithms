// Serialization
// Using PreOrder Traversal.

// We use -1 for NULL.
// Assume -1 is not present in the tree as data.



// Example 1
//
//                                10
//                              /   \
//                            20    30
//
// Serialize 10 20 -1 -1 30 -1 -1

// Example 2
//                                10
//                               /
//                             20
//
// Serialize 10 20 -1 -1 -1

// Example 3
//                                10
//                               /
//                             20
//                            /
//                          30
//                            \
//                             40
//
// Serialize 10 20 30 -1 40 -1 -1 -1 -1




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

// Serialization
const int EMPTY = -1;
void Serialize(Node *root, vector<int> &arr)
{
  if(root == NULL)
  {
    arr.push_back(EMPTY);
    return;
  }

  arr.push_back(root -> key);
  Serialize(root->left, arr);
  Serialize(root->right, arr);
}
// Time Complexity :- 0(n)
// Auxiliary Space :- 0(n)




// Deserialization
const int EMPTY = -1;
int index = 0;
Node *Deserialize(vector<int> &arr)
{
  if(index == arr.size())
    return NULL;

  int val = arr[index];
  index++;

  if(val == EMPTY)
    return NULL;

  Node *root  new Node(val);
  root -> left = Deserialize(arr);
  root -> rigth = Deserialize(arr);

  return root;
}
// Time Complexity :- 0(n)
// Auxiliary Space :-


int main()
{
  // Node *root = new Node(10);
  //
  // root -> left = new Node(20);
  // root -> right = new Node(30);
  //
  // root -> left -> left = new Node(40);
  // root -> left -> right = new Node(50);
  //
  // root -> right -> right = new Node(60);
  //
  // root -> left -> right -> left = new Node(70);
  // root -> left -> right -> right = new Node(80);

  vector<int> arr;
  // Serialize(root, arr);

  Deserialize(arr);

  // for(int it : arr)
    // cout<<it<<" ";

  return 0;
}
