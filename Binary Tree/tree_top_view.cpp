#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node* right;
    struct node* left;
    node(int val){
        data=val;
        right=NULL;
        left=NULL;
    }
};
struct tree{
    node*insert(node*root,int data){
        if(root==NULL){
            return new node(data);
        }
        else{
            node* cur;
            if(data<=root->data){
                cur= insert(root->left,data);
                root->left=cur;
            }
            else{
                cur=insert(root->right,data);
                root->right=cur;
            }
        }
        return root;
    }
};
void topview(node*root,int dis,int level,map<int,pair<int,int>>&map){
    if(root==NULL){
        return;
    }
    if(map.find(dis)==map.end()||level<map[dis].second){
        map[dis]={root->data,level};
    }
    topview(root->left,dis-1,level+1,map);
    topview(root->right,dis+1,level+1,map);
}
void printtopview(node*root){
    map<int,pair<int,int>> map;
    topview(root,0,0,map);
    for(auto it:map){
        cout<<it.second.first<<" ";
    }
}
int main(){
    tree s;
    int t;
    node *root=NULL;
    cin>>t;
    while(t--){
        int data;
        cin>>data;
        root=s.insert(root,data);
    }
    printtopview(root);
}
