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

void levelOrder(Node * root) {
queue<Node*> q;
        q.push(root);
        while (!q.empty())
        {
            Node* root = q.front();
            q.pop();
            cout << root->data << ' ';
            if (root->left) q.push(root->left);
            if (root->right) q.push(root->right);
        }

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
    mytree.levelOrder(root);
    return 0;
}