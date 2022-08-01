// Convert B-tree to DLL without using extra space ie use the same memory
// B-Tree.

// A B-Tree can be constructed only and only with INORDER traversal combined with
// PREORDER or POSTORDER traversal.
// Can't be constructed with preorder and postorder traversal.

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

void Inorder(Node *root){
    if(root!=NULL){
        Inorder(root->left);
        cout<<root->key<<" ";
        Inorder(root->right);
    }
}


// We'll construct this tree from preorder traversal and use inorder to put left
// and right subtrees.

// is = inorder start, ie = inorder end
int PreIndex = 0;
Node *ConstructTree(vector<int> inorder, vector<int> preorder, int is, int ie)
{
  if(is > ie)
    return NULL;

  Node *root = new Node(preorder[PreIndex++]);

  int InIndex;
  for(int i=is; i<ie; i++)
    if(inorder[i] == root->key)
    {
      InIndex = i;
      break;
    }
  root -> left = ConstructTree(inorder, preorder, is, InIndex-1);
  root -> right = ConstructTree(inorder, preorder, InIndex+1, ie);

  return root;
}


// Time Complexity :- O(n^2), where n is the no of nodes.
// Auxiliary Space :-


// Can be done in O(n) using hashsets.



int main()
{
  vector<int> inorder = {20, 10, 30};
  vector<int> preorder = {10, 20, 30};

  Node *root = ConstructTree(inorder, preorder, 0, inorder.size()-1);

  Inorder(root);



  return 0;
}
