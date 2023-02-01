#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<int> adj[], int u, int v){
	adj[u].push_back(v);
	adj[v].push_back(u);
}
void printGraph(vector<int> adj[], int v){
	for (int i= 1; i < v; ++i){
		cout << "list of vertex "<< i << " head "<<endl;
        cout<<i;
		for (auto x : adj[i]){
		cout << "-> " << x;
        }
		cout<<endl;
	}
}
int main(){
    int n,m;
    //n=number of vertex
    //m=number of edges
    cin>>n>>m;
    vector <int> a[n+1];
    int v,u;
    for(int i=0;i<m;i++){
        // input 2 vertex of an edge
        cin>>v>>u;
        addEdge(a,v,u);
    }
    printGraph(a,n+1);
}