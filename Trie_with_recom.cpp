#include<bits/stdc++.h>
using namespace std;

struct node{

    bool is_end=0;
    int occ=0;
    node *child[26];

    node(){
        is_end=0;
        occ=0;
        for(int i=0;i<26;i++){
            child[i]=NULL;
        }
    }

};

class my_trie{

    private:
    node *trie_dict;
    vector<string> search_recom;
    

    public:

    my_trie(){
        trie_dict=new node();
        search_recom.clear();
    }


    void insert(string s){
        int n=s.size();
        
        node *st=trie_dict;

        for(int i=0;i<n;i++){
            int ch=s[i]-'a';
            if(st->child[ch]==NULL){
                st->child[ch]=new node();
            }
            st=st->child[ch];
        }
        
        st->is_end=1;
        st->occ++;
    }


    int get_no_occ(string s){
        int n=s.size();
        
        node *st=trie_dict;

        for(int i=0;i<n;i++){
            int ch=s[i]-'a';
            if(st->child[ch]==NULL){
                return 0;
            }
            st=st->child[ch];
        }

        return st->occ;
    }

    bool search(string s){
        int n=s.size();
      
        node *st=trie_dict;

        for(int i=0;i<n;i++){
            int ch=s[i]-'a';
            if(st->child[ch]==NULL){
                return 0;
            }
            st=st->child[ch];
        }

        return (st->is_end==1);
    }


    void dfs(node *pt,string curr){
        
        if(pt->is_end){
            search_recom.push_back(curr);
        }

        for(int i=0;i<26;i++){
            if(pt->child[i]){
                string ns=curr+char('a'+i);
                dfs(pt->child[i],ns);
            }
        }
    }


    vector<string> get_recommend(string s){
        int n=s.size();
        search_recom.clear();
        vector<string> search_res;
        
        node *st=trie_dict;

        for(int i=0;i<n;i++){
            int ch=s[i]-'a';
            if(st->child[ch]==NULL){
                return search_res;
            }
            st=st->child[ch];
        }
        dfs(st,"");
        

        for(auto it:search_recom){
            string r=s+it;
            search_res.push_back(r);
        }

        return search_res;
    }


    
    










};

template <typename T>
void print_vector(vector<T> v){
    for(auto it:v){
        cout<<it<<" ";
    }
    cout<<endl;
}

int main(){
    my_trie test_trie=my_trie();

    test_trie.insert("hari");
    test_trie.insert("hariii");
    test_trie.insert("kavita");
    test_trie.insert("karri");
    test_trie.insert("sweet");
    test_trie.insert("xbox");

    auto recomend=test_trie.get_recommend("har");
    print_vector(recomend);








}
