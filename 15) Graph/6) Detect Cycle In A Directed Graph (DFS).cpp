#include<bits/stdc++.h>
using namespace std;


class Solution
{
public:
  bool checkForCycle(int node, vector<int> adj[], int visited[], int dfs_visited[])
  {
    visited[node] = 1;
    dfs_visited[node] = 1;

    for(auto it : adj[node])
    {
      if(visited[it] == false)
      {
        if(checkForCycle(it, adj, visited, dfs_visited))
          return true;
      }
      else if(dfs_visited[it])
        return true;
    }
    dfs_visited[node] = 0;
    return false;
  }

  bool isCyclic(int v, vector<int> adj[])
  {
    int visited[v] = {0}, dfs_visited[v] = {0};

    for(int i=0; i<v; i++)
    {
      if(visited[i] == false)
      {
        if(checkForCycle(i, adj, visited, dfs_visited) == true)
          return true;
      }
    }
    return false;
  }

  void addEdge(vector<int> adj[], int u, int v)
  {
    adj[u].push_back(v);
  }
};

int main()
{
  int v = 7;
  vector<int> adj[v];

  Solution object;

  object.addEdge(adj, 0, 1);
  object.addEdge(adj, 1, 2);
  object.addEdge(adj, 3, 2);
  object.addEdge(adj, 2, 4);
  object.addEdge(adj, 5, 3);
  object.addEdge(adj, 3, 6);
  object.addEdge(adj, 4, 5);

  object.isCyclic(v, adj) ? cout<<"YES" : cout<<"NO";

  return 0;
}
