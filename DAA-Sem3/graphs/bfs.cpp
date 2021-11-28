// Program to print BFS traversal from a given
// source vertex. BFS(int s) traverses vertices
// reachable from s.
#include<iostream>
#include <list>

using namespace std;


class Graph
{
	int n; 

	list<int> *adj;

public:

	Graph(int V);

	void edgeForGraph(int v, int w);

	void BFS(int s);
};

//Constructor to declare the no of vertices 
Graph::Graph(int no)
{
	this->n = no;
	adj = new list<int>[no];
}

//Function to add edge between vertices to the graph
void Graph::edgeForGraph(int v, int w)
{
	adj[v].push_back(w); 
}

//Function to perform bfs with help of a queue
void Graph::BFS(int s)
{

	bool *visited = new bool[n];
	for(int i = 0; i < n; i++)
		visited[i] = false;

	list<int> queue;

	visited[s] = true;
	queue.push_back(s);


	list<int>::iterator i;

	while(!queue.empty())
	{

		s = queue.front();
		cout << s << " ";
		queue.pop_front();


		for (i = adj[s].begin(); i != adj[s].end(); ++i)
		{
			if (!visited[*i])
			{
				visited[*i] = true;
				queue.push_back(*i);
			}
		}
	}
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

    int v;

    cout << "\nEnter the vertex to start from : ";
    
    cin >> v;

	cout << "\nBreadth First Search is : "; g.BFS(v);

	return 0;
}
