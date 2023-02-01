#include<bits/stdc++.h>
using namespace std;
void dfs(int node,unordered_map<int,bool> &vis,stack<int> &st,unordered_map<int,list<int>> & adj){
    vis[node]=true;
    for(auto nbr:adj[node]){
        if(!vis[nbr]){
            dfs(nbr,vis,st,adj);
        }
    }
    st.push(node);
}

void revdfs(int node,unordered_map<int,bool> &vis,unordered_map<int,list<int>> &adj){
    vis[node]=true;

    for(auto nbr:adj[node]){
        if(!vis[nbr]){
            revdfs(nbr,vis,adj);
        }
    }
}
int kosaraju_algo(int n,int m,vector<vector<int>> & edges){
    unordered_map<int,list<int>> adj;
    for(int i=0;i<m;i++){
        int u=edges[i][0];
        int v= edges[i][1];

        adj[u].push_back(v);
    }

    stack<int> st;
    unordered_map<int,bool> vis;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i,vis,st,adj);
        }
    }

    //transpose of graph
    unordered_map<int,list<int>> transpose;
    for(int i=0;i<n;i++){
        vis[i]=0;
        for(auto nbr: adj[i]){
            transpose[nbr].push_back(i);
        }
    }
    int ans=0;
    while(!st.empty()){
        int top=st.top();
        st.pop();
        if(!vis[top]){
            ans++;
            revdfs(top,vis,transpose);
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
        vector<int>components;
        components.push_back(x);
        components.push_back(y);
        edges.push_back(components);
    }

    int ans=kosaraju_algo(n,m,edges);
    cout<<ans<<endl;
}