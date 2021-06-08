#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	struct node *prev;
	struct node *next;
};
struct node *head=NULL;
void insertnode(int data){
	 node *newnode =new  node;
	newnode->data=data;
	newnode->prev=NULL;
	newnode->next=head;

	if(head!=NULL){
		head->prev=newnode;
	}
	head=newnode;
}

void display(){
	struct node *current=head;
while(current!=NULL){
		cout<<"data = "<<current->data<<endl;
		current=current->next;
	}
}
void deletenode(int q){
	struct node *p=head,*temp;
	while(p->next!=NULL){
		if(p->next->data==q){     //because of this data is being deleted
			temp=p->next;
			p->next=temp->next;
			temp->next->prev=temp->prev;
			delete(temp);
		}
		p=p->next;
	}
	
}
int main(){
int n,a,m;
cin>>n;
for(int i=0;i<n;i++){
	cin>>a;
	insertnode(a);
}
display();
cin>>m;
int b[m];
for(int i=0;i<m;i++){
	cin>>b[i];
}
for(int i=0;i<m;i++){
deletenode(b[i]); // this will delete the data in the node we have write data value not the node value to delete
}
display();
}
