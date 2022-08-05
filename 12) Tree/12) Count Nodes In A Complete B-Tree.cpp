
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
  Node *left;
  Node *right;
  Node(int x){
      key=x;
      left=right=NULL;
  }
};

// Naive Solution
// It's simple traverse every node recursively and keep a count.

//______________________________________________________________________________

int CountNodes(Node *root)
{
  int left_height = 0, right_height = 0;
  Node *current = root;

  while(current != NULL)
  {
    left_height++;
    current = current -> left;
  }

  current = root;

  while(current != NULL)
  {
    right_height++;
    current = current -> right;
  }

  if(left_height == right_height)
    return pow(2, left_height) - 1;
  else
    return 1 + CountNodes(root->left) + CountNodes(root->right);
}
// Time Complexity :- O(Logn * Logn)




int main()
{
  Node *root = new Node(10);

  root -> left = new Node(20);
  root -> right = new Node(30);

  root -> left -> left = new Node(40);
  root -> left -> right = new Node(50);

  root -> right -> right = new Node(60);

  root -> left -> left -> left = new Node(70);
  root -> left -> left -> right = new Node(80);

  cout<<CountNodes(root);

}
