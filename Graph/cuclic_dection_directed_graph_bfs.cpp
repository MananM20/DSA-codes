#include<bits/stdc++.h>
using namespace std;
void cyclicbfs(int n,int m,vector<pair<int,int>>& edges){
    unordered_map<int,list<int>> adj;
    for(int i=0;i<m;i++){
        int u= edges[i].first-1;
        int v= edges[i].second-1;

        adj[u].push_back(v);
    }
    int count=0;
    vector<int> indegree(n);
    for(auto i:adj){
        for(auto j:i.second){
            indegree[j]++;
        }
    }
    queue<int> q;
    for(int i=0;i<n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int front=q.front();

        q.pop();
        count++;
        for(auto neighbour:adj[front]){
            indegree[neighbour]--;
            if(indegree[neighbour]==0){
                q.push(neighbour);
            }
        }
    }
    if(count==n) cout<<"NO contain cycle"<<endl;
    else cout<<"YES does not contain cycle"<<endl;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>>edges;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        edges.push_back(make_pair(x,y));
    }
    //string ans=
    cyclicbfs(n,m,edges);
    //cout<<ans<<endl;
}