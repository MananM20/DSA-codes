#include<bits/stdc++.h>
using namespace std;
int partation(int a[],int lb,int ub){
	int piviot,end,start;
	piviot=a[lb];
	start=lb;
	end=ub;
	while(start<end){               // (start>end) will sort the array in descending order
		while(a[start]<=piviot){
			start++;
		}
		while(a[end]>piviot){
			end--;
		}
		if(start<end){
			swap(a[start],a[end]);
		}
	}
	swap(a[lb],a[end]);
	return end;
}
int quicksort(int a[],int lb,int ub){
	int k;
	if(lb<ub){
		k=partation(a,lb,ub);
		quicksort(a,lb,k-1);
		quicksort(a,k+1,ub);
	}
}
int main(){
	cout<<"size of array:-"<<endl;
	int n;
	cin>>n;
	int a[n],lb=0,ub=n-1;
	cout<<"enter elements in array:"<<endl;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	quicksort(a,lb,ub);
	cout<<"sorted array is:-"<<endl;
	for(int i=0;i<n;i++){
		cout<<" "<<a[i];
	}
}
