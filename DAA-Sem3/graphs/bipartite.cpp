// TEST FOR BIPARTITEDNESS

#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v){
	adj[u].push_back(v);
	adj[v].push_back(u);
}

bool checkBipartite(vector<int> adj[], int v,vector<bool>& vis, vector<int>& C){
	for (int u : adj[v]) {
		if (vis[u] == false) {
            vis[u] = true;
            C[u] = !C[v];
			if (!checkBipartite(adj, u, vis, C))
				return false;
		}
		else if (C[u] == C[v])
			return false;
	}
	return true;
}



int main(){
    int V,E,e1,e2,x;

    cout<<"Enter the number of Vertices: ";
    cin>>V;
    cout<<"Enter the number of Edges: ";
    cin>>E;

	vector<int> adj[V + 1];

	vector<bool> vis(V + 1);
	vector<int> C(V + 1);
    

    cout<<"The vertices are: ";
    for(int i=0;i<V;i++){
        cout<<i<<" ";
    }
    cout<<endl;
    for(int i=0;i<E;i++){
        cout<<"Enter edge "<<i+1<<": ";
        cin>>e1>>e2;
        addEdge(adj,e1,e2);
    }

	vis[1] = true;
	C[1] = 0;

	if (checkBipartite(adj, 1, vis, C)) {
		cout << "Graph is Bipartite";
	}
	else {
		cout << "Graph is not Bipartite";
	}
    cout<<endl;
	return 0;
}
