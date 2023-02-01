#include<bits/stdc++.h>
using namespace std;
void prepare_adj(unordered_map<int,set<int>>& adjlist,vector<pair<int,int>> &edges){
    for(int i=0;i<edges.size();i++){
        int u= edges[i].first;
        int v=edges[i].second;
        
        adjlist[u].insert(v);
        adjlist[v].insert(u);
    }
}
void bbfs(unordered_map<int,set<int>> &adjlist,unordered_map<int,bool> &visited,
vector<int> &ans,int node){
    queue<int>q;
    q.push(node);
    visited[node]=1;
    while(!q.empty()){
        int frontnode=q.front();
        q.pop();
        //add frontnode to ans
        ans.push_back(frontnode);

        for(auto i: adjlist[frontnode]){
            if(!visited[i]){
                q.push(i);
                visited[i]=1;
            }
        }
    }
}
vector<int> bfs(int n,vector<pair<int,int>> edges){
    unordered_map<int,set<int>> adjlist;
    vector<int> ans;
    unordered_map<int,bool> visited;
    prepare_adj(adjlist,edges);
    // traverse all componemts of graph
    for(int i=0;i<n;i++){
        if(!visited[i]){
            bbfs(adjlist,visited,ans,i);
        }
    }
    return ans;
}
int main(){
    int vertex,edge;
    cin>>vertex>>edge;
    vector<pair<int,int>> edges;

    for(int i=0;i<edge;i++){
        int x,y;
        cin>>x>>y;
        edges.push_back(make_pair(x,y));
    }
    vector<int> ans=bfs(vertex,edges);
    for(auto i: ans){
        cout<<i<<" ";
    }
}