// Ancestors of 60 are 60, 40, 30, 20, 10.
// Ancestors of 65 are 65 and 10.
// Lowest Common Ancestors (LCA) of 80 and 40 is 20,
// and that of 20 and 30 is 20.
//
//                                10
//                              /   \
//                            20    65
//                          /   \
//                        30    80
//                       /  \     \
//                     40   50    90
//                    /            \
//                  60             18
//
//




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


// Naive Solution

// bool findPath(Node *root, vector<Node *> &p, int n)
// {
//   if(root == NULL)
//     return false;
//
//   p.push_back(root);
//
//   if(root -> key == n)
//     return true;
//
//   if( findPath(root->left, p, n) || findPath(root->right, p, n) )
//     return true;
//
//   p.pop_back();
//
//   return false;
// }
//
//
// Node *LCA(Node *root, int n1, int n2)
// {
//   vector<Node *> path1, path2;
//
//   if( findPath(root, path1, n1) == false || findPath(root, path2, n2) == false )
//     return NULL;
//
//   for(int i=0; i<path1.size()-1 && i<path2.size()-1; i++)
//     if(path1[i+1] != path2[i+1])
//       return path1[i];
//   return NULL;
// }

// Time Complexity :- O(n)

//______________________________________________________________________________

// Effecient Solution.
// ALthough both naive and effecient solution require same TC and AS, Effecient
// solution traverses the tree only once and also takes less space in the worst
// case.


// 1) Requires one traversal and 0(h) extra space for the recursive traversal.
// 2) Assume that both n1 and n2 exist in the tree. Does not give correct
// result when only one(n1 or n2) exists.

// --------IDEA--------
// We do normal recursive traversal.
// We have the following cases for every node.
// 1) If it is same as n1 or n2.
// 2) If one of ots subtrees contains n1 and other one contains n2.
// 3) If one of it's subtrees contains both n1 and n2.
// 3a) It's left subtree contains both n1 and n2
// 3b) It's right subtree contains both n1 and n2.
// 4) If none of it's subtrees contains n1 and n2.


Node *LCA(Node *root, int n1, int n2)
{
  if(root == NULL)
    return NULL;

  if(root -> key == n1 || root -> key == n2) // case 1
    return root;

  Node *LCA1 = LCA(root->left, n1, n2);
  Node *LCA2 = LCA(root->right, n1, n2);

  if(LCA1 != NULL && LCA2 != NULL) // case 2
    return root;

  if(LCA1 != NULL) // case 3a
    return LCA1;
  else // case 3b and case 4
    return LCA2;
}
// Time Complexity :- 0(n)
// Auxiliary Space :- 0(h)





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

  // Node *root=new Node(10);
	// root->left=new Node(20);
	// root->right=new Node(30);
	// root->right->left=new Node(40);
	// root->right->right=new Node(50);
  // int n1=20, n2=30;

  Node *ans = LCA(root, 70, 80);
  cout<<"LCA : "<<(ans -> key);

}
