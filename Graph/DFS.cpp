#include<bits/stdc++.h>
using namespace std;
void prepare_adj(unordered_map<int,set<int>> &adj,vector<vector<int>> &edges){
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];

        adj[u].insert(v);
        adj[v].insert(u);
    }
}
void dfscall(int node,unordered_map<int,bool> &visited,unordered_map<int,set<int>> &adj,
vector<int>&components){
    components.push_back(node);
    visited[node]=true;

    for(auto i: adj[node]){
        if(!visited[i]){
            dfscall(i,visited,adj,components);
        }
    }
}
vector<vector<int>> dfs(int v,int e,vector<vector<int>> &edges){
    unordered_map<int,set<int>> adj;
    //prepare_adj(adj,edges);
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];

        adj[u].insert(v);
        adj[v].insert(u);
    }
    vector<vector<int>> ans;
    unordered_map<int,bool> visited;
    for(int i=0;i<v;i++){
        if(!visited[i]){
            vector<int> components;
            dfscall(i,visited,adj,components);
            ans.push_back(components);
        }
    }
    return ans;
}
int main(){
    int v,e;
    cin>>v>>e;
    vector<vector<int>> edges;
    for(int i=0;i<e;i++){
        vector<int>componemts;
        int x,y;
        cin>>x>>y;
        componemts.push_back(x);
        componemts.push_back(y);
        edges.push_back(componemts);
    }
    vector<vector<int>> ans=dfs(v,e,edges);
    cout<<ans.size()<<endl;
    for(auto i : ans){
        for(auto j:i){
            cout<<j<<" ";
        }cout<<endl;
    }
}