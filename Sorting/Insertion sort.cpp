#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,temp,j;
	cout<<"enter size of array"<<endl;
	cin>>n;
	int a[n];
	cout<<"elements in array"<<endl;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=1;i<n;i++){
		temp=a[i];
		j=i-1;
		while(j>=0 && a[j]>temp){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=temp;
	}
	cout<<"sorted array is"<<endl;
	for(int i=0;i<n;i++){
		cout<<" "<<a[i];
	}
	return 0;
}
