#include <bits/stdc++.h>
using namespace std;

class TrieNode {
    
    public:
    unordered_map<char,TrieNode*>children;
    bool isEndOfword;
    
    TrieNode(){
        isEndOfword = false;
    }
    
};

class Trie {
    
    private:
    TrieNode* root;
    
    public:
    Trie(){
        root = new TrieNode();
    }
    
    void insert(string s)
    {
        
        TrieNode * current = root;
        
        for(char x:s){
            
            if(current->children.find(x) == current->children.end()){
                current->children[x] = new TrieNode();
            }
            current = current->children[x];
        }
        
        current->isEndOfword=true;
    }
    
    bool search(string word) 
    {
        
        TrieNode* current = root;
        
        for(char c:word){
            
            if(current->children.find(c)==current->children.end()){
                return false;
            }
            current = current->children[c];
        }
        
        return current!=nullptr && current->isEndOfword==true;
     
    }
    
    
};


int main() 
{
     Trie trie;
     trie.insert("apple");
     trie.insert("appl");
     
     if(trie.search("appl")){
         cout<<"yes appl is there "<<endl;
     }else{
         cout<<"No"<<endl;
     }
     
     trie.search("Apple")==true ? cout<<"found"<<endl : cout<<"Not found"<<endl;
      
     
	
}




