#include<bits/stdc++.h>
using namespace std;



void BFS(vector<int> adj[], int v, int s, int dist[])
{
  bool visited[v] = {false};

  queue<int> q;

  visited[s] = true;
  q.push(s);

  while(q.empty() == false)
  {
    int u = q.front();
    q.pop();

    for(auto v : adj[u])
    {
      if(visited[v] == false)
      {
        dist[v] = dist[u] + 1;
        visited[v] = true;
        q.push(v);
      }
    }
  }
}
// Time Complexity :- O(V + E)

void addEdge(vector<int> adj[], int u, int v)
{
  adj[u].push_back(v);
  adj[v].push_back(u);
}

int main()
{

  int V=4;
	vector<int> adj[V];
	addEdge(adj, 0, 1);
	addEdge(adj, 1, 2);
	addEdge(adj, 2, 3);
	addEdge(adj, 0, 2);
	addEdge(adj, 1, 3);

  int dist[V] = {INT_MAX};

	dist[0] = 0;
	BFS(adj, V, 0, dist);

  for(int i=0; i<V; i++)
    cout<<dist[i]<<" ";

  return 0;
}
