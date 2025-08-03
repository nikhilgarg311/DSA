// User function template for C++
class TrieNode{
  public:
  TrieNode* children[26];
  bool isTerminal;
  
  TrieNode(){
      isTerminal=false;
      for(int i=0;i<26;i++){
        children[i]=NULL;
      }
  }
  
    
};

class Trie {
  public:
    TrieNode *root;
    Trie() {
        // implement Trie
        root= new TrieNode();
    }
    
    
    void insertUtil(TrieNode *root, string word){
        if(word.length()==0){
            root->isTerminal=true;
            return;
        }
        
        int index= word[0]-'a';
        TrieNode* child;
        if(root->children[index]!=NULL){
            child= root->children[index];
            
        }
        else{
            child= new TrieNode();
            root->children[index]=child;
        }
        
        insertUtil(child,word.substr(1));
    }
    
    bool searchUtil(TrieNode *root, string word){
        
        if(word.length()==0){
            return root->isTerminal;
        }
        
        int index= word[0]-'a';
        
        if(root && root->children[index]!=NULL){
            return searchUtil(root->children[index],word.substr(1));
        }
        else{
            return false;
        }
        
        
    }
    
    bool prefixUtil(TrieNode *root, string word){
        
        if(word.length()==0){
            return true;
        }
        
        int index= word[0]-'a';
        
        if(root && root->children[index]!=NULL){
            return prefixUtil(root->children[index],word.substr(1));
        }
        else{
            return false;
        }
        
        
    }

    void insert(string &word) {
        // insert word into Trie
        insertUtil(root,word);
    }

    bool search(string &word) {
        // search word in the Trie
        return searchUtil(root,word);
    }
    

    bool isPrefix(string &word) {
        // search prefix word in the Trie
        return prefixUtil(root,word);
    }
};
