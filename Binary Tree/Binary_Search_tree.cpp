#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	struct node *left,*right;
	node(int val){
		data=val;
		left=NULL;
		right=NULL;
	}
};

node *insertnode(node *root,int val){
	if(root==NULL){
		return new node(val);
	}
	if(val<root->data){
		root->left=insertnode(root->left,val);
	}
	else{
		root->right=insertnode(root->right,val);
	}
	return root;
}
void inorder(node* root){              // inoder means to print the binary tree in LNR(left,node,right)
	if(root==NULL){
		return ;
	}
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
}
void preorder(node* root){
	if(root==NULL){
		return;
	}
	cout<<root->data<<" ";          //preorder means to print the binary tree in NLR(node,left,right)
	preorder(root->left);
	preorder(root->right);
}
void postorder(node* root){
	if(root==NULL){
		return;
	}
	postorder(root->left);             //postorder means to print the binary tree in LRN(left,right,node)
	postorder(root->right);
	cout<<root->data<<" ";
}
node* searchbst(node* root, int key){
	if(root==NULL){
		return NULL;
	}
	if(root->data==key){
		return root;
	}
	if(root->data>key){
		return searchbst(root->left,key);
	}
	else{
		return searchbst(root->right,key);
	}
}
node* inordersucc(node* root){
	node* current=root;
	while(current&&current->left!=NULL){
		current=current->left;
	}
	return current;
}
node* deletebst(node* root, int key){
	if(key<root->data){
		root->left=deletebst(root->left,key);
	}
	else if(key>root->data){
		root->right=deletebst(root->right,key);
	}
    else{
		if(root->left==NULL){
			node* temp=root->right;
			free(root);
			return temp;
		}
		else if(root->right==NULL){
			node* temp=root->left;
			free(root);
			return temp;
		}
		node*temp=inordersucc(root->right);
		root->data=temp->data;
		root->right=deletebst(root->right,temp->data);
	}
	return root;
}
int main(){
node *root=NULL;
root=insertnode(root,15);
insertnode(root,7);
insertnode(root,16);
insertnode(root,37);
insertnode(root,5);
insertnode(root,2);
inorder(root);
cout<<" "<<endl;
preorder(root);
cout<<" "<<endl;
postorder(root);
cout<<" "<<endl;
if(searchbst(root,5)==NULL){
	cout<<"key does'nt exist";
}
else{
	cout<<"key exist"<<endl;
}
root=deletebst(root,5);
inorder(root);
}
