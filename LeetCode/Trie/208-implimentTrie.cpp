#include<bits/stdc++.h>
using namespace std;
struct node{
    bool isEnd;
    vector<node*> childrens{26, nullptr};
};

class Trie {
    node* root = nullptr;
public:
    Trie() {
        root = new node;
        root->isEnd = false;
    }
    
    void insert(string word) {
        node* current = root;
        for(char & c : word){
            int idx = c-'a';
            if(current->childrens[idx]){
                current = current->childrens[idx];
            }
            else{
                current->childrens[idx] = new node;
                current->childrens[idx]->isEnd = false;
                current = current->childrens[idx];
            }
        }
        current->isEnd = true;
    }
    
    bool search(string word) {
        node * current = root;
        for(char & c: word){
            int idx = c - 'a';
            if(current->childrens[idx]){
                current = current->childrens[idx];
            }
            else{
                return false;
            }
        }
        return current->isEnd;
    }
    
    bool startsWith(string prefix) {
        node * current = root;
        for(char & c: prefix){
            int idx = c - 'a';
            if(current->childrens[idx]){
                current = current->childrens[idx];
            }
            else{
                return false;
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */