#include<bits/stdc++.h>
using namespace std;
void prepare_adj(unordered_map<int,list<int>>& adj,vector<vector<int>> &edges,int m){
    for(int i=0;i<m;i++){
        int u=edges[i][0];
        int v=edges[i][1];


        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}
bool cycledfs(int node,int parent,unordered_map<int,bool> &visited,unordered_map<int,list<int>> &adj){
    visited[node]=true;

    for(auto neighbour:adj[node]){
        if(!visited[neighbour]){
            bool cycledec=cycledfs(neighbour,node,visited,adj);
            if(cycledec){
                return true;
            }
        }
        else if(neighbour!=parent){
                return true;
            }
    }
    return false;
}
string cycle(int n,int m,vector<vector<int>> &edges){
    unordered_map<int,list<int>> adj;
    prepare_adj(adj,edges,m);
    unordered_map<int,bool> visited;
    int parent=-1;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            bool ans=cycledfs(i,parent,visited,adj);
            if(ans==1){
                return "Yes";
            }
        }
    }
    return "No";
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> edges;
    for(int i=0;i<m;i++){
        vector<int>components;
        int x,y;
        cin>>x>>y;
        components.push_back(x);
        components.push_back(y);
        edges.push_back(components);
    }
    string ans=cycle(n,m,edges);
    cout<<ans<<endl;
}