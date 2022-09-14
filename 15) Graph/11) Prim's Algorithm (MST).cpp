#include<bits/stdc++.h>
using namespace std;


class Solution
{
public:
  minimum_spanning_tree(int vertices, int edges, vector<pair<int, int>> adj)
  {
    int parent[vertices];
    int key[vertices] = { INT_MAX };
    bool MSTset[vertices] = { false };


  }

};

int main()
{
  Solution object;
  int vertices, edges;
  cin>>vertices>>edges;

  vector<pair<int, int>> adj[vertices];

  int node1, node2, weight;
  for(int i=0; i<edges; i++)
  {
    cin>>node1>>node2>>weight;
    adj[node1].push_back(make_pair(node2, weight));
    adj[node2].push_back(make_pair(node1, weight));
  }

  minimum_spanning_tree(vertices, edges, adj);


  return 0;
}
