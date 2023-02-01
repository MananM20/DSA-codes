#include<bits/stdc++.h>
using namespace std;
vector<int> shortest(int n,int m,int s,int t,vector<pair<int,int>> &edges){
    unordered_map<int,list<int>> adj;
    for(int i=0;i<m;i++){
        int u=edges[i].first;
        int v= edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    unordered_map<int,bool> visited;
    unordered_map<int,int> parent;
    queue<int> q;
    q.push(s);
    visited[s]=true;
    parent[s]=-1;
    while(!q.empty()){
        int front= q.front();
        q.pop();
        for(auto i: adj[front]){
            if(!visited[i]){
                visited[i]=true;
                parent[i]=front;
                q.push(i);
            }
        }
    }

    vector<int> ans;
    int currentnode=t;
    ans.push_back(t);
    while(currentnode!=s){
        currentnode=parent[currentnode];
        ans.push_back(currentnode);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int main(){
    int n,m,s,t;
    cin>>n>>m;
    cin>>s>>t;
    vector<pair<int,int>> edges;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        edges.push_back(make_pair(x,y));
    }
    vector<int> ans=shortest(n,m,s,t,edges);
    for(auto i: ans){
        cout<<i<<" ";
    }
}