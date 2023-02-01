#include<bits/stdc++.h>
using namespace std;
void prepare_adj(unordered_map<int,set<int>>& adj,vector<vector<int>> &edges,int m){
    for(int i=0;i<m;i++){
        int u=edges[i][0];
        int v=edges[i][1];


        adj[u].insert(v);
        adj[v].insert(u);
    }
}
bool cyclebfs(int source,unordered_map<int,bool> &visited,unordered_map<int,set<int>> &adj){
    unordered_map<int ,int>parent;
    parent[source]=-1;
    visited[source]=1;
    queue<int>q;
    q.push(source);
    while(!q.empty()){
        int front =q.front();
        q.pop();
       for(auto neighbour:adj[front]){
        if(visited[neighbour]==true && neighbour!= parent[front]){
            return true;
        }
        else if(!visited[neighbour]){
            q.push(neighbour);
            visited[neighbour]=1;
            parent[neighbour]=front;
        }
       } 
    }
    return false;
}
string cycle(int n,int m,vector<vector<int>> &edges){
    unordered_map<int,set<int>> adj;
    prepare_adj(adj,edges,m);
    unordered_map<int,bool> visited;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            bool ans=cyclebfs(i,visited,adj);
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