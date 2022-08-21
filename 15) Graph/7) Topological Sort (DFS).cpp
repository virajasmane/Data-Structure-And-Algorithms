#include<bits/stdc++.h>
using namespace std;


class Solution
{
public:
  void findTopoSort(int node, stack<int> &st, vector<bool> &visited, vector<int> adj[])
  {
    visited[node] = true;

    for(auto it : adj[node])
    {
      if(visited[it] == false)
        findTopoSort(it, st, visited, adj);
    }
    st.push(node);
  }

  vector<int> toposort(int v, vector<int> adj[])
  {
    stack<int> st;

    vector<bool> visited(v, false);
    for(int i=0; i<v; i++)
    {
      if(visited[i] == false)
        findTopoSort(i, st, visited, adj);
    }

    vector<int> result;
    while(st.empty() == false)
    {
      result.push_back(st.top());
      st.pop();
    }

    return result;
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


  vector<int> result = object.toposort(v, adj);

  for(auto it : result)
    cout<<it<<" ";

  return 0;
}
