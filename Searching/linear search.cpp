#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,a=0;
	cin>>n;
	int b[n];
	for(int i=0;i<n;i++){
		cin>>b[i];
	}
	cout<<"enter the data to be found"<<endl;
	cin>>m;
	for(int i=0;i<n;i++){
		if(b[i]==m){
			cout<<"data found at index "<<i+1;
			a=a+1;
		}
	}
	if(a==0){
		cout<<"element not found"<<endl;
	}
	return 0;
}
