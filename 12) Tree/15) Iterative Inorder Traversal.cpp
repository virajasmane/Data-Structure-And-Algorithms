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

// We will use a stack DS

void IterativeInorder(Node *root)
{
  stack<Node *> s;
  Node *curr = root;

  while(curr != NULL || s.empty() == false)
  {
    while(curr != NULL)
    {
      s.push(curr);
      curr = curr -> left;
    }
    curr = s.top();
    s.pop();
    cout<<(curr -> key)<<" ";
    curr = curr -> right;
  }
}
// Time Complexity :- 0(n)
// Auxiliary Space :- O(h)

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

  IterativeInorder(root);

  return 0;
}
