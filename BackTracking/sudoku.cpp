#include<bits/stdc++.h>
using namespace std;
bool issafe(int row,int col,vector<vector<int>> &board,int val){
    for(int i=0;i<board.size();i++){
        //row check
        if(board[row][i]==val){
        return false;
    }
    //col check
    if(board[i][col]==val){
        return false;
    }
    //3*3 matrix check and formula learn
    if(board[3*(row/3)+i/3][3*(col/3)+i%3]==val){
        return false;
    }
    }
return true;
}

bool solve(vector<vector<int>> &board){
    int n=board[0].size();
    for(int row=0;row<n;row++){
        for(int col=0;col<n;col++){
            if(board[row][col]==0){
                for(int val=1;val<10;val++){
                    if(issafe(row,col,board,val)){
                        board[row][col]==val;

                    bool aage_solution_possiable=solve(board);
                    if(aage_solution_possiable){
                        return true;
                    }
                    else{
                        //backtracking
                        board[row][col]=0;
                    }
                    }
                }
                return false;
            }
        }
    }
    return true;
}
void sudoku(vector<vector<int>> &board){
    solve(board);
}
int main(){
    // input nahi diya hai aur dena bhi nahi aata hai
    //to kisi site pe jaker run ker na
    sudoku(vector<vector<int>>board;)
}