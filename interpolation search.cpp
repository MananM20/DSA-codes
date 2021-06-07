#include<bits/stdc++.h>
using namespace std;
int interpolationsearch(int a[],int n,int d){
	int start,end,pos;
	start=0;
	end=n-1;
	while(start<=end&&d>=a[start]&&d<=a[end]){
		pos=start+(((double)(end-start)/(a[end]-a[start]))*(d-a[start]));
		if(a[pos]==d){
			return pos;
		}
		else if(a[pos]<d){
			start=pos+1;
		}
		else{
			end=pos-1;
		}
	}
}
int main(){
	int n,d,e;
	cout<<"enter number of elements"<<endl;
	cin>>n;
	int a[n];
	cout<<"enter elements in array"<<endl;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	cout<<"data to be searched"<<endl;
	cin>>d;
	e=interpolationsearch(a,n,d);
	cout<<e+1<<endl;
	
}
