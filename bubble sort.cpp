#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,temp,flag=0;
	cout<<"number of elements in array"<<endl;
	cin>>n;
	int a[n];
	cout<<"input elements in array"<<endl;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-1-i;j++){
			if(a[j]>a[j+1]){
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				flag=1;
			}
		}
		if(flag==0){
	    break;
		}
	}
	cout<<"sorted array is"<<endl;
	for(int i=0;i<n;i++){
		cout<<" "<<a[i];
	}
	
	return 0;
}

