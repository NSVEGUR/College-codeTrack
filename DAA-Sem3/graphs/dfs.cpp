#include<iostream>
#include <bits/stdc++.h>
using namespace std;


class Graph
{
public:
	
    map<int, bool> visited;
	map<int, list<int>> adj;

	void edgeForGraph(int v, int w);

	void DFS(int v);
};

//Function to add edge between vertices to the graph
void Graph::edgeForGraph(int v, int w)
{
	adj[v].push_back(w); 
}

//Function to perform dfs (recursive)
void Graph::DFS(int v)
{

	visited[v] = true;
	cout << v << " ";

	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			DFS(*i);
}


int main()
{   
	Graph g;
    
    int n,m,e1,e2;

    cout << "\nEnter the number of vertices and edges of the graph : ";
    cin >> n >> m;

    cout << "\nVertices are : ";
    for(int i=0; i<n; i++)
    {
        cout << i << " ";
    }

    cout << endl;

    for(int i=0; i<m; i++)
    {
        cout << "\nEnter the edges : ";

        cin >> e1 >> e2;

        g.edgeForGraph(e1, e2);

    }

    int v;

    cout << "\nEnter the vertex to start from : ";
    
    cin >> v;

	cout << "\nDepth First Search is : "; g.DFS(v);

	return 0;
}


