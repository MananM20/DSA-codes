#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>prims_algo(int n,int m,vector<vector<int>>& edges,int source){
    unordered_map<int,list<pair<int,int>>> adj;
    for(int i=0;i<m;i++){
        int u= edges[i][0];
        int v= edges[i][1];
        int w= edges[i][2];

        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }
    vector<int> key(n+1,INT_MAX);
    vector<bool> mst(n+1,false);
    vector<int> parent(n+1,-1);

    key[source]=0;
    parent[source]=-1;

    for(int i=0;i<n;i++){

        int mini=INT_MAX;
        int u;
        for(int j=1;j<=n;j++){
            if(mst[j]==false && key[j]<mini){
                u=j;
                mini=key[j];
            }
        }
        //
        mst[u]=true;

        for(auto it:adj[u]){
            int v=it.first;
            int w=it.second;
            if(mst[v]==false && w<key[v]){
                parent[v]=u;
                key[v]=w;
            }
        }
    }

    vector<vector<int>> ans;
    for(int i=2;i<=n;i++){
        int u=parent[i];
        int v=i;
        int w= key[i];
        vector<int> components;
        components.push_back(u);
        components.push_back(v);
        components.push_back(w);
        ans.push_back(components);
    }
    return ans;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> edges;
    for(int i=0;i<m;i++){
    int v,u,w;
    cin>>u>>v>>w;
    vector<int> components;
    components.push_back(u);
    components.push_back(v);
    components.push_back(w);
    edges.push_back(components);
    }
    int source;
    cin>>source;
    vector<vector<int>> ans =prims_algo(n,m,edges,source);
    sort(ans.begin(),ans.end());
    for(auto i:ans){
        for(auto j:i){
            cout<<j<<" ";
        }cout<<endl;
    }
}