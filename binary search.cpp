#include<bits/stdc++.h>
using namespace std;
 int binarysearch(int a[],int n,int data){
	int l,r,mid;
	 l=a[0];
	 r=a[n-1];
	 while(l<=r){
	 mid=(l+r)/2;
	 if(data==a[mid]){
	 	return mid;
	 }
	 else if(data<a[mid]){
	 	r=mid-1;
	 }
	 else{
	 	l=mid+1;
	 }
}
 }
 int main(){
 	int n,data,b=0;
 	cin>>n;
 	int a[n],c[n];
 	for(int i=0;i<n;i++){
 		cin>>a[i];
	 }
	 cout<<"data to be found"<<endl;
	 cin>>data;
	 sort(a,a+n);
	 b= b + binarysearch(a,n,data);
	 if(b!=0){
	 	cout<<"data found at index"<<b+1<<endl;
	 }
	 else{
	 	cout<<"data not found"<<endl;
	 }
}
