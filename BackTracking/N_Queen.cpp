#include<bits/stdc++.h>
using namespace std;
void addsolutiontoans(vector<vector<int>> &ans,vector<vector<int>> &board,int n){
    vector<int>temp;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            temp.push_back(board[i][j]);
        }
    }
    ans.push_back(temp);
}
bool issafe(int row,int coloumn,vector<vector<int>> &board,int n){
    int x=row;
    int y=coloumn;
    //check for same row
    while(y>=0){
        if(board[x][y]==1)
        return false;
        y--;
    }
    //check for diagnal 1 
    x=row;
    y=coloumn;
    while(x>=0 && y>=0){
        if(board[x][y]==1)return false;
        x--;y--;
    }
    // check for diagnal 2 
    x=row;
    y=coloumn;
    while(x<n && y>=0){
        if(board[x][y]==1)return false;
        x++;y--;
    }
    return true;
}
void solve(int coloumn,vector<vector<int>> &ans,vector<vector<int>> &board,int n){
    if(coloumn==n){
        addsolutiontoans(ans,board,n);
        return;
    }
    //checking for 1 case and baki recursion sambhal le ga
    for(int row=0;row<n;row++){
        if(issafe(row,coloumn,board,n)){
            board[row][coloumn]=1;
            solve(coloumn+1,ans,board,n);
            //backtrack
            board[row][coloumn]=0;
        }

    }
}
void print(vector<vector<int>> ans){
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans.size();j++){
            cout<<ans[i][j]<<" ";
        }cout<<endl;
    }
}
void nqueen(int n){
    vector<vector<int>>ans;
    vector<vector<int>>board;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            board[i][j]=0;
        }
    }
    int coloumn=0;
    solve(coloumn,ans,board,n);
    vector<vector<int>>a=ans;
    print(a);
}
int main(){
    int n;//size of board
    cin>>n;
    nqueen(n);
    
}