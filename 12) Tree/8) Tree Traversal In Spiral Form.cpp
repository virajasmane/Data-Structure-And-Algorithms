// Spiral form Example.
//
//                   10
//                /     \
//               20     30
//             /   \      \
//            40   50     60
//                /  \
//               70  80
//
// Spiral traversal :- 10 30 20 40 50 60 80 70

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

// Method 1
void PrintSpiral1(Node *root)
{
  if(root == NULL)
    return ;

  queue<Node *> q;
  stack<int> s;
  bool reverse = false;

  q.push(root);
  while(q.empty() == false)
  {
    int count = q.size();

    for(int i=0; i<count; i++)
    {
      Node *current = q.front();
      q.pop();

      if(reverse)
        s.push(current -> key);
      else
        cout<<(current -> key)<<" ";

      if(current -> left != NULL)
        q.push(current -> left);
      if(current -> right != NULL)
        q.push(current -> right);
    }

    if(reverse)
    {
      while(s.empty() == false)
      {
        cout<<s.top()<<" ";
        s.pop();
      }
    }
    reverse  = !reverse;
    // cout<<endl;
  }
}

// Time Complexity :- O(n)
// Auxiliary Space :-

// Find out where extra work is done and if something can be done to remove the
// extra work. Then only move to method 2.

//______________________________________________________________________________


// Method 2
// 1st method seems to be doing extra work for alternate level nodes, they first
// go in to the queue, come out of the queue then go into the stack come out out
// the stack,
// try to optimise that thing in this solution.

// Solution

// Use two stacks s1 and s2, now think !!





// 1) Push root to stack s1
// 2) While any of the stack is not empty
//       While s1 is not empty
//          a) pop a node, print it.
//          b) Push children of poped node into stack s2,
//              (Order of pushing should be LEFT node first then RIGHT node)
//       While s2 is not empty
//          a) pop a node, print it.
//          b) Push children of poped node into stack s1 in reverse order, ie
//              (Order of pushing should be RIGHT node first then LEFT node)




void PrintSpiral2(Node *root)
{
  if(root == NULL)
    return ;

  stack<Node *> s1;
  stack<Node *> s2;
  s1.push(root);

  while( !s1.empty() || !s2.empty())
  {
    while(!s1.empty())
    {
      Node *temp = s1.top();
      s1.pop();
      cout<<(temp -> key)<<" ";

      if(temp -> left)
        s2.push(temp -> left);
      if(temp -> right)
        s2.push(temp -> right);
    }

    while(!s2.empty())
    {
      Node *temp = s2.top();
      s2.pop();
      cout<<(temp -> key)<<" ";

      if(temp -> right)
        s1.push(temp -> right);
      if(temp -> left)
        s1.push(temp -> left);
    }
  }
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

  PrintSpiral2(root);

  return 0;
}
