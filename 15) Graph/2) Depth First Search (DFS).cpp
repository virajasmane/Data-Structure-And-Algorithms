// Here 3 versions of DFS are discussed.

#include<bits/stdc++.h>
using namespace std;



// VERSION 1

void DFS_Recursion(vector<int> adj[], int s, bool visited[])
{
  visited[s] = true;
  cout<<s<<" ";

  for(auto it : adj[s])
    if(visited[it] == false)
      DFS_Recursion(adj, it, visited);
}

void DFS(vector<int> adj[], int v, int s)
{
  bool visited[v] = {false};

  DFS_Recursion(adj, s, visited);
}

void addEdge(vector<int> adj[], int u, int v)
{
  adj[u].push_back(v);
  adj[v].push_back(u);
}

int main()
{
  int v = 5;
	vector<int> adj[v];
	addEdge(adj, 0, 1);
	addEdge(adj, 0, 2);
	addEdge(adj, 2, 3);
	addEdge(adj, 1, 3);
	addEdge(adj, 1, 4);
	addEdge(adj, 3, 4);

	DFS(adj, v, 0);

	return 0;
}

//______________________________________________________________________________

// VERSION 2

// void DFSRec(vector<int> adj[], int s, bool visited[])
// {
//     visited[s]=true;
//     cout<< s <<" ";
//
//     for(int u:adj[s]){
//         if(visited[u]==false)
//             DFSRec(adj,u,visited);
//     }
// }
//
// void DFS(vector<int> adj[], int V){
//     bool visited[V];
// 	for(int i = 0;i<V; i++)
// 		visited[i] = false;
//
//     for(int i=0;i<V;i++){
//         if(visited[i]==false)
//             DFSRec(adj,i,visited);
//     }
// }
//
// void addEdge(vector<int> adj[], int u, int v){
//     adj[u].push_back(v);
//     adj[v].push_back(u);
// }
//
// int main()
// {
// 	int V=5;
// 	vector<int> adj[V];
// 	addEdge(adj,0,1);
// 	addEdge(adj,0,2);
// 	addEdge(adj,1,2);
// 	addEdge(adj,3,4);
//
// 	cout << "Following is Depth First Traversal for disconnected graphs: "<< endl;
// 	DFS(adj,V);
//
// 	return 0;
// }

//______________________________________________________________________________

// VERSION 3

// void DFSRec(vector<int> adj[], int s, bool visited[])
// {
//     visited[s]=true;
//
//     for(int u:adj[s]){
//         if(visited[u]==false)
//             DFSRec(adj,u,visited);
//     }
// }
//
// int DFS(vector<int> adj[], int V){
//     int count=0;
//     bool visited[V];
// 	for(int i = 0;i<V; i++)
// 		visited[i] = false;
//
//     for(int i=0;i<V;i++){
//         if(visited[i]==false)
//             {DFSRec(adj,i,visited);count++;}
//     }
//     return count;
// }
//
// void addEdge(vector<int> adj[], int u, int v){
//     adj[u].push_back(v);
//     adj[v].push_back(u);
// }
//
// int main()
// {
// 	int V=5;
// 	vector<int> adj[V];
// 	addEdge(adj,0,1);
// 	addEdge(adj,0,2);
// 	addEdge(adj,1,2);
// 	addEdge(adj,3,4);
//
// 	cout << "Number of connected components: "<< DFS(adj,V);
//
// 	return 0;
// }

// Time Complexity :- O(V + E)
