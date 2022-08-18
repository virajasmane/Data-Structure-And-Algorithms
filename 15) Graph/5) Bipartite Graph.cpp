#include<bits/stdc++.h>
using namespace std;


// Using BFS.
// class Solution
// {
// public:
//   bool checkBFS(int s, vector<int> adj[], vector<int> &color)
//   {
//     queue<int> q;
//     q.push(s);
//
//     color[s] = 1;
//
//     while(q.empty() == false)
//     {
//       int node = q.front();
//       q.pop();
//
//       for(auto it : adj[node])
//       {
//         if(color[it] == -1)
//         {
//           color[it] = 1 - color[node];
//           q.push(it);
//         }
//         else if(color[it] == color[node])
//           return false;
//       }
//     }
//     return true;
//   }
//
//   bool checkBipartite(vector<int> adj[], int v)
//   {
//     vector<int> color(v, -1);
//
//     for(int i=0; i<v; i++)
//     {
//       if(color[i] == -1)
//         if(checkBFS(i, adj, color) == false)
//           return false;
//     }
//     return true;
//   }
//
//   void addEdge(std::vector<int> adj[], int u, int v)
//   {
//     adj[u].push_back(v);
//     adj[v].push_back(u);
//   }
// };
//
// int main()
// {
//   int v = 8;
//   vector<int> adj[v];
//
//   Solution object;
//
//   object.addEdge(adj, 0, 1);
//   object.addEdge(adj, 1, 2);
//   object.addEdge(adj, 2, 3);
//   object.addEdge(adj, 2, 4);
//   object.addEdge(adj, 3, 5);
//   object.addEdge(adj, 3, 6);
//   // object.addEdge(adj, 4, 5);
//   object.addEdge(adj, 4, 7); // comment this line and next line and uncomment the line above for YES
//   object.addEdge(adj, 5, 7);
//
//
//   object.checkBipartite(adj, v) ? cout<<"YES" : cout<<"NO";
//
//
//   return 0;
// }
//______________________________________________________________________________

// Using DFS
class Solution
{
public:
  bool bipartiteDFS(int node, vector<int> adj[], vector<int> &color)
  {
    if(color[node] == -1)
      color[node] = 1;

    for(auto it : adj[node])
    {
      if(color[it] == -1)
      {
        color[it] = 1 - color[node];
        if(bipartiteDFS(it, adj, color) == false)
          return false;
      }
      else if(color[node] == color[it])
        return false;
    }
    return true;
  }

  bool checkBipartite(vector<int> adj[], int v)
  {
    vector<int> color(v, -1);

    for(int i=0; i<v; i++)
    {
      if(color[i] == -1)
        if(bipartiteDFS(i, adj, color) == false)
          return false;
    }
    return true;
  }

  void addEdge(std::vector<int> adj[], int u, int v)
  {
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
};

int main()
{
  int v = 8;
  vector<int> adj[v];

  Solution object;

  object.addEdge(adj, 0, 1);
  object.addEdge(adj, 1, 2);
  object.addEdge(adj, 2, 3);
  object.addEdge(adj, 2, 4);
  object.addEdge(adj, 3, 5);
  object.addEdge(adj, 3, 6);
  object.addEdge(adj, 4, 5);
  // object.addEdge(adj, 4, 7); // comment this line and next line and uncomment the line above for YES
  // object.addEdge(adj, 5, 7);

  object.checkBipartite(adj, v) ? cout<<"YES" : cout<<"NO";


  return 0;
}
