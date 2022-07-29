#include<bits/stdc++.h>
using namespace std;

// Following operations are carried out,

// 1) Inorder Traversal (DFS).
// 2) Preorder Traversal (DFS).
// 3) Postorder Traversal (DFS).
// 4) Height of the Binary Tree.
// 5) Breadth First Search(BFS) or Level Order Traversal
// 6) Level Order Traversal (line by line) (Method 1).
// 7) Level Order Traversal (line by line) (Method 2).
// 8) Size Of Binary Tree.
// 9) Maximum in the Binary Tree.
// 10) Print Left view of Binary Tree.


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

//______________________________________________________________________________
// 1) Inorder Traversal (DFS).
void inorder(Node *root)
{
  if(root != NULL)
  {
    inorder(root -> left);
    cout<<(root -> key)<<" ";
    inorder(root -> right);
  }
}
// Time Complexity :- 0(n), where n is no of nodes.
// Auxiliary Space :- 0(h), where h is height of the tree.
//______________________________________________________________________________


//______________________________________________________________________________
// 2) Preorder Traversal (DFS).
void preorder(Node *root)
{
  if (root != NULL)
  {
    cout<<(root -> key)<<" ";
    preorder(root -> left);
    preorder(root -> right);
  }
}
// Time Complexity :- 0(n), where n is no of nodes.
// Auxiliary Space :- 0(h), where h is height of the tree.
//______________________________________________________________________________


//______________________________________________________________________________
// 3) Postorder Traversal (DFS).
void postorder(Node *root)
{
  if(root != NULL)
  {
    postorder(root -> left);
    postorder(root -> right);
    cout<<(root -> key)<<" ";
  }
}
// Time Complexity :- 0(n), where n is no of nodes.
// Auxiliary Space :- 0(h), where h is height of the tree.
//______________________________________________________________________________



//______________________________________________________________________________
// 4) Height of the Binary Tree.
int height(Node *root)
{
  if(root == NULL)
    return 0;
  else
    return ( max( height(root->left), height(root->right) ) + 1 );
}
// Time Complexity :- 0(n), where n is no of nodes.
// Auxiliary Space :- 0(h), where h is height of the tree.
//______________________________________________________________________________




//______________________________________________________________________________
// 5) Breadth First Search(BFS) or Level Order Traversal
// One way is to first find height of the B-Tree and then print nodes at k distance from it
// But this is ineffecient solution and its Time Complexity is O(h x n).
// An effecient solution uses queue DS, now think how ?
void levelorder(Node *root)
{
  if(root == NULL)
    return;

  queue<Node *> q;
  q.push(root);
  while(q.empty() == false)
  {
    Node *current = q.front();
    q.pop();

    cout<<(current -> key)<<" ";

    if(current -> left != NULL)
      q.push(current -> left);

    if(current -> right != NULL)
      q.push(current -> right);
  }

}
// Time Complexity :- 0(n), where n is no of nodes.
// Interesting fact about queue, there will only be one level at a time in the queue
// So aux space is equal to width of binary tree
// Auxiliary Space :- O(n) or 0(w), 0(w) is accurate, where w is width of the B-Tree, which can range from 1 to n.
//______________________________________________________________________________




//______________________________________________________________________________
// 6) Level Order Traversal (line by line) (Method 1).
// When we traverse the last node of the level, the next level is completely
// into the queue. Using this info we solve the problem.
void levelorderlbl1(Node *root)
{
  if(root == NULL)
    return;

  queue<Node *> q;
  q.push(root);
  q.push(NULL);

  while(q.size() > 1)
  {
    Node *current = q.front();
    q.pop();

    if(current == NULL)
    {
      cout<<endl;
      q.push(NULL);
      continue;
    }

    cout<<(current -> key)<<" ";

    if(current -> left != NULL)
      q.push(current -> left);
    if(current -> right != NULL)
      q.push(current -> right);
  }
}
// Time Complexity :- 0(n), where n is no of nodes.
// Interesting fact about queue, there will only be one level at a time in the queue
// So aux space is equal to width of binary tree
// Auxiliary Space :- O(n) or 0(w), 0(w) is accurate, where w is width of the B-Tree, which can range from 1 to n.
//______________________________________________________________________________




//______________________________________________________________________________
// 7) Level Order Traversal (line by line) (Method 2).
void levelorderlbl2(Node *root)
{
  if(root == NULL)
    return;

  queue<Node *> q;
  q.push(root);

  while(q.empty() == false)
  {
    int count = q.size(); // Take care here size of queue has to be taken into diff var
    for(int i=0; i<count; i++)// Dont put i<q.size() here bc it changes in the loop.
    {
      Node *current = q.front();
      q.pop();
      cout<<(current -> key)<<" ";
      if(current -> left != NULL)
        q.push(current -> left);
      if(current -> right != NULL)
        q.push(current -> right);
    }
    cout<<endl;
  }
}
// Time Complexity :- 0(n), where n is no of nodes.
// Interesting fact about queue, there will only be one level at a time in the queue
// So aux space is equal to width of binary tree
// Auxiliary Space :- O(n) or 0(w), 0(w) is accurate, where w is width of the B-Tree, which can range from 1 to n.
//______________________________________________________________________________




//______________________________________________________________________________
// 8) Size Of Binary Tree.
int getSize(Node *root)
{
  if(root == NULL)
    return 0;
  else
    return (1 + getSize(root -> left) + getSize(root -> right));
}
// Time Complexity :- O(n), where n is no of nodes.
// Auxiliary Space :- O(h), where h is the height of B-Tree.
//______________________________________________________________________________




//______________________________________________________________________________
// 9) Maximum in the Binary Tree.
int getMax(Node *root)
{
  if(root == NULL)
    return INT_MIN;
  else
    return max({root->key, getMax(root->left), getMax(root->right)});
}
// Time Complexity :- O(n), where n is no of nodes.
// Auxiliary Space :- O(h), where h is the height of B-Tree.


//______________________________________________________________________________
// 10) Print Left view of Binary Tree.
// Recursive solution

int maxlevel = 0;

void Printleft(Node *root, int level)
{
  if(root == NULL)
    return;

  if(maxlevel < level)
  {
    cout<<(root -> key)<<" ";
    maxlevel = level;
  }

  Printleft(root -> left, level+1);
  Printleft(root -> right, level+1);
}

void Printleftview(Node *root)
{
  Printleft(root, 1);
}
// Time Complexity :- O(n), where n is no of nodes.
// Auxiliary Space :- O(h), where h is the height of B-Tree.



// Iterative solution
void PrintleftviewI(Node *root)
{
  if(root == NULL)
    return;

  queue<Node *> q;
  q.push(root);

  while(q.empty() == false)
  {
    int count = q.size(); // Take care here size of queue has to be taken into diff var
    for(int i=0; i<count; i++)// Dont put i<q.size() here bc it changes in the loop.
    {
      Node *current = q.front();
      q.pop();
      if(i == 0)
        cout<<(current -> key)<<" ";
      if(current -> left != NULL)
        q.push(current -> left);
      if(current -> right != NULL)
        q.push(current -> right);
    }
  }
}
// Time Complexity :- 0(n), where n is no of nodes.
// Interesting fact about queue, there will only be one level at a time in the queue
// So aux space is equal to width of binary tree
// Auxiliary Space :- O(n) or 0(w), 0(w) is accurate, where w is width of the B-Tree, which can range from 1 to n.


//______________________________________________________________________________







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

  cout<<"Inorder Traversal :- ";
  inorder(root);
  cout<<endl;
  cout<<endl;

  cout<<"Preorder Traversal :- ";
  preorder(root);
  cout<<endl;
  cout<<endl;

  cout<<"Postorder Traversal :- ";
  postorder(root);
  cout<<endl;
  cout<<endl;

  cout<<"Height :- "<<height(root);
  cout<<endl;

  cout<<"Level Order Traversal :- ";
  levelorder(root);
  cout<<endl;
  cout<<endl;

  cout<<"Level Order Traversal (line by line) :- "<<endl;
  levelorderlbl2(root);
  cout<<endl;
  cout<<endl;

  cout<<"Size Of The Binary Tree :- ";
  cout<<getSize(root);
  cout<<endl;
  cout<<endl;

  cout<<"Maximum In The Binary Tree :- ";
  cout<<getMax(root);
  cout<<endl;
  cout<<endl;

  cout<<"Left View Of Binary Tree :- ";
  PrintleftviewI(root);
  cout<<endl;
  cout<<endl;

  return 0;
}
