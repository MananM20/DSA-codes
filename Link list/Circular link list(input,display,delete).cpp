#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	struct node *next;
};
struct node *head=NULL,*tail;
void insertnode(int data){
	node *newnode=new node;
	newnode->data=data;
	newnode->next=NULL;
	if(head==NULL){
		head=newnode;
		tail=newnode;
	}
	else{
		tail->next=newnode;
		tail=newnode;
	}
	tail->next=head;
}
void display(){
	struct node *current=head;
	if(head==NULL){
		cout<<"empty list"<<endl;
	}
	else{
		while(current->next!=head){
		cout<<"data is ="<<current->data<<endl;
		current=current->next;
	}
cout<<"data is ="<<current->data<<endl;	
}
}
void deletenode(int n){
	struct node *temp1,*temp2;
	temp1=tail->next;
	int i=1;
	while(i<n-1){
		temp1=temp1->next;
        i++; 
 	}
	temp2=temp1->next;
	temp1->next=temp2->next;
	delete(temp2);
}
int main(){
	insertnode(2);
	insertnode(3);
	insertnode(4);
	deletenode(3);
	display();
}

