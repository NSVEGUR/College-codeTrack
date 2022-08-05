#include <bits/stdc++.h>
using namespace std;
#define N 100000

vector<int> graph1[N], graph2[N];

bool visited1[N], visited2[N];

//Add edge to the graph
void edgeForGraph(int u, int v)
{
	graph1[u].push_back(v);
	graph2[v].push_back(u);
}

//perform dfs
void dfs1(int x)
{
	visited1[x] = true;

	for (auto i : graph1[x])
		if (!visited1[i])
			dfs1(i);
}

//perform dfs
void dfs2(int x)
{
	visited2[x] = true;

	for (auto i : graph2[x])
		if (!visited2[i])
			dfs2(i);
}

//check for connectedness
bool connectedness(int n)
{
	
	memset(visited1, false, sizeof visited1);
	dfs1(0);

	
	memset(visited2, false, sizeof visited2);
	dfs2(0);

	for (int i = 0; i < n; i++) 
    {

		if (!visited1[i] and !visited2[i])
			return false;
	}

	return true;
}


int main()
{
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

        edgeForGraph(e1, e2);

    }

	if (connectedness(n))
		cout << "\nIt is a connected graph \n";
	else
		cout << "\nIt is not a connected graph\n";

	return 0;
}
