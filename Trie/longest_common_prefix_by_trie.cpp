#include<bits/stdc++.h>
using namespace std;

class Trienode{
    public:
        char data;
        Trienode *children[26];//because english has 26 alphabet
        int childcount;
        bool isTermial;


        Trienode(char ch){
            data=ch;
            for(int i=0;i<26;i++){
                children[i]=NULL;
            }
            childcount=0;
            isTermial=false;
        }

};

class Trie{
    public:
    Trienode* root;

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
    Trienode* child;
    //present
    if(root->  children[index]!=NULL){
    child=root->children[index];
    }
    //absent
    else{
        child=new Trienode(word[0]);
        root->childcount++;
        root->children[index]=child;
    }
    //recursion
    insertutil(child,word.substr(1));
    }
    void insertword(string word){
        insertutil(root,word);
    }

    void lcf(string str,string &ans){
        for(int i=0;i<str.length();i++){
            char ch= str[i];
            if(root->childcount==1){
                ans.push_back(ch);
                //aage badh na hai
                int index=ch-'a';
                root=root->children[index];
            }
            else break;

            if(root->isTermial) break;
        }
    }

};
string longestcommprefix(vector<string> &arr,int n){
    
    Trie *t=new Trie();
    //insert to trie
    for(int i=0;i<n;i++){
        t->insertword(arr[i]);
    }
    string first=arr[0];
    string ans="";
    t->lcf(first,ans);
    return ans;
}
int main(){
    //input me "n" aur string lena hai
    //aur us ko lonfestcommprefix function me bhej dena hai
    int n;cin>>n;
    vector<string> s;
    for(int i=0;i<n;i++){
        string temp;
        cin>>temp;
        s.push_back(temp);
    }
    
    string ans=longestcommprefix(s,n);
    cout<<ans;
    return 0;
}    