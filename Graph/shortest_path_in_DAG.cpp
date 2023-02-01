#include<bits/stdc++.h>
using namespace std;
void dfs(int node,unordered_map<int,bool> &visited,stack<int> &s,unordered_map<int,list<pair<int,int>>> &adj){
    visited[node]=true;

    for(auto neighbour:adj[node]){
        if(!visited[neighbour.first]){
            dfs(neighbour.first,visited,s,adj);
        }
    }
    s.push(node);
}
vector<int> shortest_path(int n,int m,vector<vector<int>> &edges,int source){
    unordered_map<int,list<pair<int,int>>> adj;
    for(int i=0;i<m;i++){
        int u= edges[i][0];
        int v=edges[i][1];
        int w= edges[i][2];
        pair<int,int> p= make_pair(v,w);
        adj[u].push_back(p);
    }
    unordered_map<int,bool> visited;
    stack<int> s;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(i,visited,s,adj);
        }
    }
    vector<int> dis(n,INT_MAX);
    dis[source]=0;
    while(!s.empty()){
        int top=s.top();

        s.pop();
        if(dis[top]!=INT_MAX){
            for(auto i:adj[top]){
                if(dis[top]+i.second<dis[i.first]){
                    dis[i.first]=dis[top]+i.second;
                }
            }
        }
    }
    return dis;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> edges;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        vector<int>components;
        components.push_back(u);
        components.push_back(v);
        components.push_back(w);
        edges.push_back(components);
    }
    int source;
    cin>>source;
    vector<int> ans=shortest_path(n,m,edges,source);
    for(auto i:ans){
        cout<<i<<" ";
    }

}