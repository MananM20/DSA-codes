#include<bits/stdc++.h>
using namespace std;
//time complexity of insert and delete is O(logn)
class heap{
    public:
    int a[100];
    int size=0;
    heap (){
        a[0]=-1;
        size=0;
    }
    void insert(int val){
        size=size+1;
        int index= size;
        a[index]=val;
        while(index>1){
            int parrent=index/2;

            if(a[parrent]<a[index]){
                swap(a[parrent],a[index]);
                index=parrent;
            }
            else{
                return;
            }
        }
    }
    void print(){
        for(int i=1;i<=size;i++){
            cout<<a[i]<<" ";
        }cout<<endl;
    }
    void deletenodefromheap(){
        //it will delete the root node of the heap means first element of array
        if(size==0){
            cout<<"nothing to delete"<<endl;
            return ;
        }
        a[1]=a[size];
        size--;
        int i=1;
        while(i<size){//1 based indexing if question is 0 based indexing then leftindex=2*i+1 and rught index =2*i+1
            int leftindex=2*i;
            int rightindex=2*i+1;
            if(leftindex<size && a[i]<a[leftindex]){
                swap(a[i],a[leftindex]);
                i=leftindex;
            }
            else if(rightindex<size && a[i]<a[rightindex]){
                swap(a[i],a[rightindex]);
                i=rightindex;
            }
            else{
                return;
            }
        }
    }
};


int main(){
    heap h;
    // inseet elements in heap
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int b;cin>>b;
        h.insert(b);
    }
    h.print();
    //enter a new element in heap
    int c;cin>>c;
    h.insert(c);
    h.print();
    h.deletenodefromheap();
    h.print();
    return 0;
}