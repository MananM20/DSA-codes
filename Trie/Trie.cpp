#include<bits/stdc++.h>
using namespace std;

class Trienode{
    public:
        char data;
        Trienode *children[26];//because english has 26 alphabet
        bool isTermial;


        Trienode(char ch){
            data=ch;
            for(int i=0;i<26;i++){
                children[i]=NULL;
            }
            isTermial=false;
        }

};
class Trie{
    public:
    Trienode* root;//variabel

    Trie()  {
        root= new Trienode('\0');
    }
    void insertutil(Trienode *root,string word){
        //base case
        if(word.length()==0){
            root->isTermial=true;
            return;
        }
        //assumption, word will be in small caps
    int index=word[0]-'a';
    Trienode* child;//variable
    //present
    if(root->  children[index]!=NULL){
    child=root->children[index];
    }
    //absent
    else{
        child=new Trienode(word[0]);
        root->children[index]=child;
    }
    //recursion
    insertutil(child,word.substr(1));
    }
    void insertword(string word){
        insertutil(root,word);
    }
    bool searchutil(Trienode *root,string word){
        //base case
        if(word.length()==0){
            return root->isTermial;
        }
        int index=word[0]-'a';
        Trienode* child;
        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else{
            return false;
        }
        return searchutil(child,word.substr(1));
    }
    bool searchword(string word){
       return searchutil(root,word);
    }
    bool prefixutil(Trienode* root,string word){
        if(word.length()==0){
            return true;
        }
        int index =word[0]-'a';
        Trienode* child;
        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else return false;

        return prefixutil(child,word.substr(1));
    }
    bool searchprefix(string prefix){
        return prefixutil(root,prefix);
    }
};

int main(){
    Trie *t=new Trie();
    t->insertword("abcd");
    cout<<"present " << t->searchword("abcd")<<endl;
    cout<<"prefix present "<<t->searchprefix("abd")<<endl;
    return 0;
}


// Time Complexity =O(l) //length of word
// search ki T.C. =O(l) //length of word