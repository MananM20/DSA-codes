#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node* right;
    struct node*left;
    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};
struct tree{
    node*insert (node*root,int data){
        if(root==NULL){
            return new node(data);
        }
        else{
            node*cur;
            if(data<=root->data){
                cur=insert(root->left,data);
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
void leftview(node*root){
    if(root==NULL){
        return ;
    }
    queue<node*>q;
    q.push(root);
    while(!q.empty()){
        int n=q.size();
        for(int i=0;i<n;i++){
            node*cur=q.front();
            q.pop();
            if(i==0){
                cout<<cur->data<<" ";
            }
            if(cur->left!=NULL) q.push(cur->left);
            if(cur->right!=NULL) q.push(cur->right);
        }
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    tree s;
    node*root=NULL;
    int t,data;
    cin>>t;
    while(t--){
        cin>>data;
        root=s.insert(root,data);
    }
    leftview(root);
}