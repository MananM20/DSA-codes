#include<bits/stdc++.h>
using namespace std;
//time complexity =O(n*m^2)
//space complexity =O(n*m)
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
    void printsuggestions(Trienode* curr,vector<string> &temp,string &prefix){
        if(curr->isTermial){
            temp.push_back(prefix);
        }
        for(char ch='a';ch<='z';ch++){
            Trienode* next =curr->children[ch-'a'];
            if(next !=NULL){
                prefix.push_back(ch);
                printsuggestions(next,temp,prefix);
                prefix.pop_back();
            }
        }
    }
    vector<vector<string>> getsuggestions(string str){
        Trienode* prev=root;
        vector<vector<string>>output;
        string prefix="";
        for(int i=0;i<str.length();i++){
            char lastch =str[i];
            prefix.push_back(lastch);
            //check last character
            Trienode* curr=prev->children[lastch-'a'];

            //if not present
            if(curr==NULL) break;

            // if found
            vector<string>temp;
            printsuggestions(curr,temp,prefix);

            output.push_back(temp);
            temp.clear();
            prev=curr;
        }
        return output;
    }
};
vector<vector<string>> phonedirectory(vector<string> &contactlist,string &querylist){
    //creation of trie
    Trie *t=new Trie();
    //insert all elements in trie
    for(int i=0;i<contactlist.size();i++){
        string str=contactlist[i];
        t->insertword(str);
    }
    return t->getsuggestions(querylist);
}
int main(){
    int n;cin>>n;
    vector<string> s;
    for(int i=0;i<n;i++){
        string temp;
        cin>>temp;
        s.push_back(temp);
    }
    string q;
    cin>>q;
    vector<vector<string>>ans=phonedirectory(s,q);
    for(auto i:ans){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }

}
