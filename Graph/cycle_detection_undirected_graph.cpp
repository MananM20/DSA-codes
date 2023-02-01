#include<bits/stdc++.h>
using namespace std;
bool cyclicdfs(int node,unordered_map<int,bool> &visited,unordered_map<int,bool> &dfscheck,unordered_map<int,list<int>> &adj){
    visited[node]=true;
    dfscheck[node]=true;

    for(auto neighbour:adj[node]){
        if(!visited[neighbour]){
            bool ans=cyclicdfs(neighbour,visited,dfscheck,adj);
            if(ans)
            return true;
        }
        else if(dfscheck[neighbour]){
            return true;
        }
    }
    dfscheck[node]=false;
    return false;
}
string cycle(int n,vector<pair<int,int>> &edges){
    unordered_map<int,list<int>> adj;
    for(int i=0;i<edges.size();i++){
        int u=edges[i].first;
        int v=edges[i].second;

        adj[u].push_back(v);

    }
    unordered_map<int,bool> visited;
    unordered_map<int,bool> dfscheck;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            bool ans=cyclicdfs(i,visited,dfscheck,adj);
            if(ans==1){
                return "true";
            }
        }
    }
    return "false";
}
 int main(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> edges;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        edges.push_back(make_pair(x,y));
    }
    string ans=cycle(n,edges);
    cout<<ans<<endl;
 }