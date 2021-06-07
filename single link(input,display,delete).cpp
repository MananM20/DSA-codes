#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	struct node *next;
};
struct node *head,*tail=NULL;
void addnode(int data){
node * newdata = new node;
	newdata->data=data;
	newdata->next=NULL;
	if(head==NULL){
		head=newdata;
		tail=newdata;
	}
	else{
		tail->next=newdata;
		tail=newdata;
	}
}
void display(){
	struct node *current=head;
	if(head==NULL){
		cout<<"empty list"<<endl;
		return;
	}
	while(current!=NULL){
		cout<<"Data= "<<current->data<<endl;
		current=current->next;
	}
}
void deletenode(int n){
	struct node* temp1=head;
	if(n==1){
		head=temp1->next;
		free(temp1);
		return;
	}
	for(int i=0;i<n-2;i++){
		temp1=temp1->next;
	}
	struct node* temp2=temp1->next;
	temp1->next=temp2->next;
	free(temp2);
}
bool compare(int a,int b){
	return a>b;
}
int main(){
	int m,a,c;
	cout<<"enter how maany numbers u want to insert"<<endl;
	cin>>m;
	cout<<"numbers are"<<endl;
	for(int i=0;i<m;i++){
		cin>>a;
		addnode(a);
	}
	display();
	cout<<"numbers to be deleted"<<endl;
	cin>>c;
	int b[c];
	cout<<"numbers are"<<endl;
	for(int i=0;i<c;i++){
		cin>>b[i];
	}
	sort(b,b+c,compare);
	for(int i=0;i<c;i++){
	deletenode(b[i]);// it will delete node at b[i] position not the value of the node 
	}
	
	display(); 
}
