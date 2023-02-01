#include<bits/stdc++.h>
using namespace std;
//this algo place the i index to its correct index to its corrent position
void heapify(int a[],int n,int i){
    int largest=i;
    int left=2*i;
    int right =2*i+1;
    if(left<n && a[largest]<a[left]){
        swap(a[largest],a[left]);
    }
    if(right<n && a[largest]<a[right]){
        swap(a[largest],a[right]);
    }
    if(largest!=i){
        swap(a[largest],a[i]);
        heapify(a,n,largest);
    }
}
int main(){
    int n;
    cin>>n;
    int a[n+1];
    a[0]=-1;
    for(int i=1;i<n+1;i++){
        cin>>a[i];
    }
    //call heapify function
    for(int i=n/2;i>0;i--){
        heapify(a,n,i);
    }
    //print
    for(int i=1;i<n+1;i++){
        cout<<a[i]<<" ";
    }
}