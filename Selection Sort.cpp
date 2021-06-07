#include<bits/stdc++.h>
using namespace std;
void swap(int a[],int i,int j){
	int temp=a[i];
	a[i]=a[j];
	a[j]=temp;
}
int main(){
	int n;
	cout<<"size of array:-"<<endl;
	cin>>n;
	int a[n];
	cout<<"enter elements in array"<<endl;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n-1;i++){
	    int	min=i;
	    for(int j=i+1;j<n;j++){
		if(a[j]<a[min]){
		    min=j;	
		    }	
		}
		if(min!=i){
		swap(a[i],a[min]);
	    }
	}
	cout<<"sorted array is"<<endl;
	for(int i=0;i<n;i++){
		cout<<" "<<a[i];
	}
}
