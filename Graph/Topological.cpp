#include<bits/stdc++.h>
using namespace std;
void topo_sort(int node,vector<bool> &visited,unordered_map <int,list<int>> &adj,stack <int> & s){
    visited[node]=1;
    for(auto neighbour:adj[node]){
        if(!visited[neighbour]){
            topo_sort(neighbour,visited,adj,s);
        }
    }
    s.push(node);
}
vector<int> topo(int n,int m,vector<vector<int>> &edges){
    unordered_map <int,list<int>> adj;
    for(int i=0;i<m;i++){
        int u =edges[i][0];
        int v= edges[i][1];

        adj[u].push_back(v);
    }
    vector<bool> visited(m);
    stack<int> s;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            topo_sort(i,visited,adj,s);
        }
    }
    vector<int> ans;
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> edges;
    for(int i=0;i<m;i++){
        vector<int> components;
        int x,y;
        cin>>x>>y;
        components.push_back(x);
        components.push_back(y);
        edges.push_back(components);
    }
    vector<int> ans=topo(n,m,edges);
    for(auto i: ans){
        cout<<i<<" ";
    }
}