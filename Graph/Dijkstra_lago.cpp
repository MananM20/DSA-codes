#include<bits/stdc++.h>
using namespace std;
vector<int> dijkstra(int n,int m,vector<vector<int>> &edges,int source){
    unordered_map<int,list<pair<int,int>>> adj;
    for(int i=0;i<m;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        int w=edges[i][2];
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }
    vector<int> dist(n,INT_MAX);
    set<pair<int,int>> st;

    dist[source]=0;
    st.insert(make_pair(0,source));

    while(!st.empty()){

        auto top =*(st.begin());

        int nodedistance =top.first;
        int topnode=top.second;

        st.erase(st.begin());

        for(auto neighbour :adj[topnode]){

            if(nodedistance+neighbour.second < dist[neighbour.first]){
                auto record =st.find(make_pair(dist[neighbour.first],neighbour.first));

                if(record != st.end()){
                    st.erase(record);
                }

                dist[neighbour.first]=nodedistance + neighbour.second;

                st.insert(make_pair(dist[neighbour.first],neighbour.first));
            }
        }
    }
    return dist;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> edges;
    for(int i=0;i<m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        vector<int> components;
        components.push_back(x);
        components.push_back(y);
        components.push_back(z);
        edges.push_back(components);
    }
    int source;
    cin>>source;
    vector<int> ans=dijkstra(n,m,edges,source);
    for(auto i: ans){
        cout<<i<<" ";
    }
}