
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


int result = 0;
int BurnTime(Node *root, int leaf, int &dist)
{
  if(root == NULL)
    return 0;

  if(root -> key == leaf)
  {
    dist = 0;
    return 1;
  }

  int left_dist = -1, right_dist = -1;

  int left_height = BurnTime(root->left, leaf, left_dist);
  int right_height = BurnTime(root->right, leaf, right_dist);

  if(left_dist != -1)
  {
    dist = left_dist + 1;
    result = max(result, dist + right_height);
  }
  else if(right_dist != -1)
  {
    dist = right_dist + 1;
    result = max(result, dist + left_height);
  }
  return max(left_height, right_height) + 1;
}



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

  int dist = -1;
  int leaf = 80;

  BurnTime(root, leaf, dist);
  cout<<result;
}
