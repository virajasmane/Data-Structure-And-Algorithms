#include<bits/stdc++.h>
using namespace std;


class Solution
{
public:
  void TopologicalSort(int node, vector<int> adj[])
  {
    vector<int> indegree(node, 0);
    for(int i=0; i<node; i++)
      for(auto it : adj[i])
        indegree[it]++;

    queue<int> q;
    for(int i=0; i<node; i++)
      if(indegree[i] == 0)
        q.push(i);

    while(q.empty() == false)
    {
      int x = q.front();
      q.pop();
      cout<<x<<" ";

      for(auto it : adj[x])
        if(--indegree[it] == 0)
          q.push(it);
    }
  }

  void addEdge(vector<int> adj[], int u, int v)
  {
    adj[u].push_back(v);
  }
};

int main()
{
  Solution object;

  int v = 5;
	vector<int> adj[v];
	object.addEdge(adj, 0, 1);
  object.addEdge(adj, 1, 3);
  object.addEdge(adj, 2, 3);
  object.addEdge(adj, 3, 4);
  object.addEdge(adj, 2, 4);

  object.TopologicalSort(v, adj);

  return 0;
}
