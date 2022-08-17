#include<bits/stdc++.h>
using namespace std;


// BFS based Solution.
// class Solution
// {
// public:
//   bool checkForCycle(int s, vector<int> adj[], vector<bool> &visited)
//   {
//     queue<pair<int, int>> q;
//
//     visited[s] = true;
//     q.push({s, -1});
//
//     while(q.empty() == false)
//     {
//       int node = q.front().first;
//       int prev = q.front().second;
//       q.pop();
//
//       for(auto it : adj[node])
//       {
//         if(!visited[it])
//         {
//           visited[it] = true;
//           q.push({it, node});
//         }
//         else if(prev != it)
//           return true;
//       }
//     }
//     return false;
//   }
//
//   bool isCycle(int V, vector<int> adj[])
//   {
//     vector<bool> visited(V, false);
//
//     for(int i=0; i<V; i++)
//       if(visited[i] == false)
//         if(checkForCycle(i, adj, visited))
//           return true;
//     return false;
//   }
// };
// Time Compleixty :- O(V+E)
//______________________________________________________________________________

// DFS based Solution

class Solution
{
public:
  bool checkForCycle(int s, int parent, vector<bool> &visited, vector<int> adj[])
  {
    visited[s] = true;

    for(auto it : adj[s])
    {
      if(visited[it] == false)
      {
        if(checkForCycle(it, s, visited, adj))
          return true;
      }
      else if(it != parent)
        return true;
    }
    return false;
  }

  bool isCycle(int V, vector<int> adj[])
  {
    vector<bool> visited(V, false);

    for(int i=0; i<V; i++)
      if(visited[i] == false)
        if(checkForCycle(i, -1, visited, adj))
          return true;
    return false;
  }
};
// Time Complexity :- Same as BFS.


void addEdge(vector<int> adj[], int u, int v)
{
  adj[u].push_back(v);
  adj[v].push_back(u);
}

int main()
{
  int V=6;
	vector<int> adj[V];
	addEdge(adj,0,1);
	addEdge(adj,1,2);
	addEdge(adj,2,4);
	addEdge(adj,4,5);
	addEdge(adj,1,3);
	addEdge(adj,2,3);

  Solution object;

  object.isCycle(V, adj) ? cout<<"Yes" : cout<<"No";

  return 0;
}
