class Trie {
public:
        struct node{
        node *child[26];
        int end=0;
        
        node(){
            for(int i=0;i<26;i++)child[i]=NULL;
        }
    };
    
    node *my_trie;
    Trie() {
        my_trie=new node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        
        node *st=my_trie;
        for(int i=0;i<word.size();i++){
            if(st->child[word[i]-'a'] == NULL){
                st->child[word[i]-'a']=new node();
            }
            st=st->child[word[i]-'a'];
            if(i == word.size()-1){
                st->end=1;
            }
        }        
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        node *st=my_trie;
        for(int i=0;i<word.size();i++){
            if(st->child[word[i]-'a'] == NULL){
                return 0;
            }
            st=st->child[word[i]-'a'];
            
        }
        return (st->end == 1);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string word) {
        node *st=my_trie;
        for(int i=0;i<word.size();i++){
            if(st->child[word[i]-'a'] == NULL){
                return 0;
            }
            st=st->child[word[i]-'a'];
        }
        return 1;
    }
};

