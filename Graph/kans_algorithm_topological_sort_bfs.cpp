#include<bits/stdc++.h>
using namespace std;
void bfs(vector<int> & ans,vector<int> & indegree,queue<int> & q,unordered_map<int,list<int>>& adj){
    while(!q.empty()){
        int front=q.front();
        q.pop();

        ans.push_back(front);

        for(auto neighbour:adj[front]){
            indegree[neighbour]--;
            if(indegree[neighbour]==0)
            q.push(neighbour);
        }
    }
}
vector<int> kans(int n,int m,vector<vector<int>> &edges){
    unordered_map<int ,list<int>> adj;
    for(int i=0;i<m;i++){
        int u=edges[i][0];
        int v=edges[i][1];

        adj[u].push_back(v);
    }
    //vector<bool> visited;
    vector<int > ans;
    vector<int> indegree(n);
    for(auto i:adj){
        for(auto j:i.second){
            indegree[j]++;
        }
    }
    queue <int> q;
    for(int i=0;i<m;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }


    bfs(ans,indegree,q,adj);
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
    vector<int> ans=kans(n,m,edges);
    for(auto i: ans){
        cout<<i<<" ";
    }
}