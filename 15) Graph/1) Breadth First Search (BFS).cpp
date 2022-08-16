// Here 3 versions of BFS are discussed.

#include<bits/stdc++.h>
using namespace std;

// 🔴 VERSION 1
// Description :- Given an undirected graph abd a source vertex 's' print BFS
//                from the given source.

// Example 1 :- s = 0
//              0
//            /  \
//           1    2
//              /  \
//             3    4
// O/P :- 0 1 2 3 4

// Example 2 :- s = 0
//                      1
//                    / | \
//                   0  |  3
//                    \ | /
//                      2
// O/P :- 0 1 2 3

// Example 3 :- s = 0
//                      1 --- 3
//                     /       \
//                    0 ------- 5
//                     \       /
//                      2 --- 4
//
// O/P :- 0 1 2 5 3 4

// v:vertices, s:source

// void BFS1(vector<int> adj[], int v, int s)
// {
//   bool visited[v] = {false};
//
//   queue<int> q;
//
//   visited[s] = true;
//   q.push(s);
//
//   while(q.empty() == false)
//   {
//     int top = q.front();
//     q.pop();
//     cout<<top<<" ";
//
//     for(auto it : adj[top])
//     {
//       if(visited[it] == false)
//       {
//         visited[it] = true;
//         q.push(it);
//       }
//     }
//   }
// }

// void addEdge(vector<int> adj[], int u, int v)
// {
//   adj[u].push_back(v);
//   adj[v].push_back(u);
// }

// int main()
// {
//   int v=5;
//   vector<int> adj[v];
//   addEdge(adj, 0, 1);
//   addEdge(adj, 0, 2);
//   addEdge(adj, 1, 2);
//   addEdge(adj, 2, 3);
//   addEdge(adj, 1, 3);
//   addEdge(adj, 3, 4);
//   addEdge(adj, 2, 4);
//
//   cout<<"Following is Breadth First Traversal: "<<endl;
//   BFS1(adj, v, 0);
//
//   return 0;
// }

//______________________________________________________________________________

// 🔴 VERSION 2
// Description :- No source given and possibly disconnected graph.

// Example 1 :-  Ye ek he graph hai jo disconnected hai
//                         0              4
//                       /   \          /  \
//                      1     2        5 -- 6
//                       \   /
//                         3
// O/P :- 0 1 2 3 4 5 6

// void BFS(vector<int> adj[], int s, bool visited[])
// {
//   queue<int> q;
//
//   visited[s] = true;
//   q.push(s);
//
//   while(q.empty() == false)
//   {
//     int top = q.front();
//     q.pop();
//     cout<<top<<" ";
//
//     for(auto it : adj[top])
//     {
//       if(visited[it] == false)
//       {
//         visited[it] = true;
//         q.push(it);
//       }
//     }
//   }
// }
//
// void BFSDisconnected(vector<int> adj[], int v)
// {
//   bool visited[v] = {false};
//
//   for(int i=0; i<v; i++)
//     if(visited[i] == false)
//       BFS(adj, i, visited);
// }
//
// void addEdge(vector<int> adj[], int u, int v)
// {
//   adj[u].push_back(v);
//   adj[v].push_back(u);
// }
//
// int main()
// {
// 	int v = 7;
// 	vector<int> adj[v];
// 	addEdge(adj,0,1);
// 	addEdge(adj,0,2);
// 	addEdge(adj,2,3);
// 	addEdge(adj,1,3);
// 	addEdge(adj,4,5);
// 	addEdge(adj,5,6);
// 	addEdge(adj,4,6);
//
// 	cout << "Following is Breadth First Traversal: "<< endl;
// 	BFSDisconnected(adj, v);
//
// 	return 0;
// }

// Time Complexity :- O(V+E), where V is no of vertices and E is no of edges

//______________________________________________________________________________

// 🔴 VERSION 3 (IQ)
// Description :- A possibly-disconnected and an undirected graph, count the
//                connected components.
// Also asked as number of islands on a graph, it is a popular interview
// question.

// Example 1 :-
//                      0            4           7
//                    /   \        /  \        /  \
//                   1     2      5 -- 6      8    9
//                    \   /                        |
//                      3                         10
// O/P :- 3

// Example 2 :-
//              0
//            /  \
//           1    2
// O/P :- 1

// The code is same as last code only minor changes in the BFSDisconnected
// function, they are highlighted in green.

void BFS(vector<int> adj[], int s, bool visited[])
{
  queue<int> q;

  visited[s] = true;
  q.push(s);

  while(q.empty() == false)
  {
    int top = q.front();
    q.pop();
    // cout<<top<<" "; 🟢

    for(auto it : adj[top])
    {
      if(visited[it] == false)
      {
        visited[it] = true;
        q.push(it);
      }
    }
  }
}

/*🟢*/ int BFSDisconnected(vector<int> adj[], int v)
{
  int count = 0; //🟢
  bool visited[v] = {false};

  for(int i=0; i<v; i++)
    if(visited[i] == false)
    {
      BFS(adj, i, visited);
      count++; //🟢
    }

  return count; //🟢
}

void addEdge(vector<int> adj[], int u, int v)
{
  adj[u].push_back(v);
  adj[v].push_back(u);
}

int main()
{
	int v = 9;
	vector<int> adj[v];
	addEdge(adj, 0, 1);
	addEdge(adj, 0, 2);
	addEdge(adj, 2, 3);
	addEdge(adj, 1, 3);
	addEdge(adj, 4, 5);
	addEdge(adj, 5, 6);
	addEdge(adj, 4, 6);
  addEdge(adj, 7, 8);

	cout<<BFSDisconnected(adj, v);

	return 0;
}
