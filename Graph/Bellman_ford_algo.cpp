#include<bits/stdc++.h>
using namespace std;
int bellmanford(int n,int m,int src,int end,vector<vector<int>> &edges){
    vector<int> dis(n+1,1e9);
    dis[src]=0;

    for(int i=1;i<=n;i++){
        for(int j=0;j<m;j++){
            int u=edges[j][0];
            int v=edges[j][1];
            int w= edges[j][2];

            if(dis[u]!=1e9 &&((dis[u]+w)<dis[v])){
                dis[v]=dis[u]+w;

            }
        }
    }
    bool flag=0;
    //check negative cycle
     for(int j=0;j<m;j++){
            int u=edges[j][0];
            int v=edges[j][1];
            int w= edges[j][2];

            if(dis[u]!=INT_MAX &&((dis[u]+w)<dis[v])){
               flag=1;
            }
    }
    if(flag==0){
        return dis[end];
    }
    return-1;
}
int main(){
    int n,m;
    cin>>n>>m;
    int src,end;
    cin>>src>>end;
    vector<vector<int>> edges;
    for(int i=0;i<m;i++){
        int x,y,w;
        cin>>x>>y>>w;
        vector<int> components;
        components.push_back(x);
        components.push_back(y);
        components.push_back(w);
        edges.push_back(components);
    }   
    
    int ans=bellmanford(n,m,src,end,edges);
    cout<<ans<<endl;
}