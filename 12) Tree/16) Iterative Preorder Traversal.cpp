// Link To the track :- https://practice.geeksforgeeks.org/tracks/DSASP-Tree/?batchId=154&tab=2


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


// Use stack DS again.

void IterativePreorder(Node *root)
{
  if(root == NULL)
    return ;

  stack<Node *> s;
  s.push(root);

  while(s.empty() == false)
  {
    Node *curr = s.top();
    cout<<(curr->key)<<" ";
    s.pop();

    if(curr -> right != NULL)
      s.push(curr -> right);

    if(curr -> left != NULL)
      s.push(curr -> left);
  }
}
// Time Complexity :- O(n)
// Auxiliary Space :- O(n)

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

  IterativePreorder(root);

  return 0;
}
