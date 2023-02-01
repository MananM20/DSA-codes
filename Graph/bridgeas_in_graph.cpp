#include<bits/stdc++.h>
using namespace std;
void dfs(int node,int parent,int &timer,vector<int> &dis,vector<int> &low,unordered_map<int,bool> &vis,unordered_map<int,list<int>> &adj,vector<vector<int>> &ans){
    vis[node]=true;
    dis[node]=low[node]=timer++;

    for(auto nbr:adj[node]){
        if(nbr==parent)continue;

        if(!vis[nbr]){
            dfs(nbr,node,timer,dis,low,vis,adj,ans);
            low[node]=min(low[node],low[nbr]);
            //check bridge
            if(low[nbr]>dis[node]){
                vector<int> result;
                result.push_back(node);
                result.push_back(nbr);
                ans.push_back(result);
            }
        }
        else{
            //back edges
            low[node]=min(low[node],dis[nbr]);
        }
    }
}


vector<vector<int>> bridges(int n,int m,vector<vector<int>>& edges){
    unordered_map<int,list<int>> adj;
    for(int i=0;i<m;i++){
        int u=edges[i][0];
        int v=edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int timer=0;
    vector<int> dis(n,-1);
    vector<int> low(n,-1);
    int parent=-1;
    unordered_map<int,bool> vis;
    vector<vector<int>> ans;
    //dfs
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i,parent,timer,dis,low,vis,adj,ans);

        }
    }
    return ans;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> edges;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        vector<int> components;
        components.push_back(x);
        components.push_back(y);
        edges.push_back(components);
    }
    cout<<endl;
    vector<vector<int>> ans=bridges(n,m,edges);
    cout<<ans.size()<<endl;
    sort(ans.begin(),ans.end());
    for( auto i: ans){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}