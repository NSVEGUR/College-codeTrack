// A C++ Program to detect cycle in a graph
#include<bits/stdc++.h>

using namespace std;

class Graph
{
	int n; 
	list<int> *adj; 

	bool checkCycle(int v, bool visited[], bool *rs); 

public:
	Graph(int V); 
	void edgeForGraph(int v, int w); 
	bool cycle(); 
};

//Constructor to intilise values
Graph::Graph(int no)
{
	this->n = no;
	adj = new list<int>[no];
}

void Graph::edgeForGraph(int v, int w)
{
	adj[v].push_back(w); 
}

//visited array - store the info whether node is visited or not
//recStack - cuurent index of the visisted array will be marked as true
bool Graph::checkCycle(int v, bool visited[], bool *recStack)
{
	if(visited[v] == false)
	{
		visited[v] = true;
		recStack[v] = true;

		list<int>::iterator i;
		for(i = adj[v].begin(); i != adj[v].end(); ++i)
		{
			if ( !visited[*i] && checkCycle(*i, visited, recStack) )
				return true;
			else if (recStack[*i])
				return true;
		}

	}
	
    recStack[v] = false; 
	return false;
}


bool Graph::cycle()
{
	
	bool *visited = new bool[n];
	bool *recStack = new bool[n];
	
    for(int i = 0; i < n; i++)
	{
		visited[i] = false;
		recStack[i] = false;
	}


	for(int i = 0; i < n; i++)
		if (checkCycle(i, visited, recStack))
			return true;

	return false;
}

int main()
{   
    int n,m,e1,e2;

    cout << "\nEnter the number of vertices and edges of the graph : ";
    cin >> n >> m;

	Graph g(n);

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

	if(g.cycle())
		cout << "\nGraph is cyclic \n";
	else
		cout << "\nGraph is not cyclic \n";
	return 0;
}
