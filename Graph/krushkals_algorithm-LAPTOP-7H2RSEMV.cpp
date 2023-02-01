#include<bits/stdc++.h>
using namespace std;
bool cmp(vector<int> &a,vector<int> &b){
    return a[2]<b[2];
}
void makeset(vector<int> &parent,vector<int> &rank,int n){
    for(int i=0;i<n;i++){
        parent[i]=i;
        rank[i]=0;
    }
}

int find_parent(vector<int> &parent,int node){
    if(parent[node]==node){
        return node;
    }
    return parent[node]=find_parent(parent,parent[node]);
}

void unionset(int u,int v,vector<int> &parent,vector<int> &rank){
    u=find_parent(parent,u);
    v=find_parent(parent,v);


    if(rank[u]<rank[v]){
        parent[u]=v;
    }
    else if(rank[u]>rank[v])
        parent[v]=u;
    else{
        parent[v]=u;
        rank[u]++;
    }
}
int min_spanning_tree_KA(int n,int m,vector<vector<int>> &edges){
    sort(edges.begin(),edges.end(),cmp);
    vector<int>parent(n);
    vector<int> rank(n);
    makeset(parent,rank,n);
    int ans=0;
    for(int i=0;i<edges.size();i++){
        int u= find_parent(parent,edges[i][0]);
        int v= find_parent(parent,edges[i][1]);
        int wt=edges[i][2];
        if(u!=v){
            unionset(u,v,parent,rank);
            ans =wt+ans;
        }
    }
    return ans;
}
vector<vector<int>> min_spanning_graph_KA(int n,int m,vector<vector<int>> &edges){
    sort(edges.begin(),edges.end(),cmp);
    vector<int>parent(n);
    vector<int> rank(n);
    makeset(parent,rank,n);
    vector<vector<int>> ans;
    for(int i=0;i<edges.size();i++){
        int u= find_parent(parent,edges[i][0]);
        int v= find_parent(parent,edges[i][1]);
        int wt=edges[i][2];
        if(u!=v){
            unionset(u,v,parent,rank);
            int a=edges[i][0];
            int b=edges[i][1];
            vector<int> components;
            components.push_back(a);
            components.push_back(b);
            components.push_back(wt);
            ans.push_back(components);
        }
    }
    return ans;
}
int main(){
    int n,m;
    cin>>n>>m;
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

    //int ans= min_spanning_tree_KA(n,m,edges);
    cout<<endl;
    vector<vector<int>> ans_graph=min_spanning_graph_KA(n,m,edges);
    sort(ans_graph.begin(),ans_graph.end());
    for(auto i: ans_graph){
        for(auto j: i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    //cout<<ans<<" ";
}