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

 int height(Node* root) {
        if(root==NULL){
            return 0;
        }
        else 
        return 1+max(height(root->left),height(root->right));// total height including first index
    }                                                        //if want to find height excluding first vertex -1 from the answer
};
int main(){
    solution mytree;
    Node* root=NULL;
    int t,data,a;
    cin>>t;
    while(t--){
        cin>>data;
        root=mytree.insert(root,data);
    }
   a= mytree.height(root);
   cout<<a<<endl;
    return 0;
}