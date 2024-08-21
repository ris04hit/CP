// template
// template_trie_tree
// template containing trie tree related functions

#include <bits/stdc++.h>
using namespace std;

//
struct TrieNode {
    bool is_leaf = false;
    vector<struct TrieNode*> child = vector<struct TrieNode*> (26);

    void append(string& word){
        struct TrieNode* root = this;
        for (char c: word){
            if (!root->child[c-'a']){
                root->child[c-'a'] = new TrieNode();
            }
            root = root->child[c-'a'];
        }
        root->is_leaf = true;
    }

    bool find(string& word){
        struct TrieNode* root = this;
        for (char c: word){
            if (root->child[c-'a']){
                root = root->child[c-'a'];
            }
            else return false;
        }
        return root->is_leaf;
    }
};
