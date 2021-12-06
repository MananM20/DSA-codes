#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    Node(int val){
        data =val;
        left=NULL;
        right=NULL;
    }
};
struct solution{
    Node* insert(Node* root, int data){
        if(root==NULL){
        return new Node(data);
    }
    else{
        Node* cur;
        if(data<=root->data){
            cur=insert(root->left,data);
            root->left=cur;
        }
        else{
            cur=insert(root->right,data);
            root->right=cur;
        }
        return root;
    }
}

void preorder(struct Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
};
int main(){
    solution mytree;
    Node* root=NULL;
    int t,data;
    cin>>t;
    while(t--){
        cin>>data;
        root=mytree.insert(root,data);
    }
    mytree.preorder(root);
    return 0;
}
