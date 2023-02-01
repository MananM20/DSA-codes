//tc=O(n^2)
#include<bits/stdc++.h>
using namespace std;
struct node {
    int data;
    struct node* left;
    struct node* right;
    node(int val){
        data= val;
        left=right=NULL;
    }
};
struct tree{
    node* insert(node* root,int data){
        if(root==NULL){
            return new node(data);
        }
        else{
            node* cur;
            if(data<=root->data){
                cur=insert(root->left,data);
                root->left=cur;
            }
            else{
                cur=insert(root->right,data);
                root->right=cur;// tc=o(n^2)
            }
        }
        return root;
    }
};
bool printlevel(node* root,int level){
    if(root==NULL){
        return false;
    }
    if(level==1){
        cout<<root->data<<" ";
        return true;
    }
    bool left=printlevel(root->left,level-1);
    bool right=printlevel(root->right,level-1);
    return left||right;
}
void levelorder(node* root){
    int level=1;
    while(printlevel(root,level)){
        level++;
    }
}
int main(){
    tree s;
    node* root=NULL;
    int n;
    cin>>n;
    while(n--){
        int data;
        cin>>data;
        root=s.insert(root,data);
    }
    levelorder(root);
}