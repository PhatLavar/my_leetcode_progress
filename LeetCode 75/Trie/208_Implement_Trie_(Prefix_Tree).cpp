#include <bits/stdc++.h>
using namespace std;

class Trie {
private:
    struct Node {
        Node* child[26];
        bool isEnd;

        Node() {
            isEnd = false;
            for (int i = 0; i < 26; i++) child[i] = nullptr;
        }
    };

    Node* root;

public:
    Trie() {
        root = new Node();    
    }
    
    void insert(string word) {
        Node* curr = root;
        for (char c : word) {
            if (curr->child[c - 'a'] == nullptr) curr->child[c - 'a'] = new Node();
            curr = curr->child[c - 'a'];
        }
        curr->isEnd = true;
    }
    
    bool search(string word) {
        Node* curr = root;
        for (char c : word) {
            if (curr->child[c - 'a'] == nullptr) return false;
            curr = curr->child[c - 'a'];
        }
        return curr->isEnd;
    }
    
    bool startsWith(string prefix) {
        Node* curr = root;
        for (char c : prefix) {
            if (curr->child[c - 'a'] == nullptr) return false;
            curr = curr->child[c - 'a'];
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