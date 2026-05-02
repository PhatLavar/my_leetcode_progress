#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    struct Node {
        Node* child[26];
        vector<string> suggestions;
        
        Node() {
            for (int i = 0; i < 26; i++) child[i] = nullptr;
        }
    };

    Node* root = new Node();

    void insert(string& word) {
        Node* curr = root;
        for (char c : word) {
            if (curr->child[c - 'a'] == nullptr) curr->child[c - 'a'] = new Node();
            curr = curr->child[c - 'a'];
            if ((int)curr->suggestions.size() < 3) curr->suggestions.push_back(word);
        }
    }

public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        for (string& product : products) insert(product);

        vector<vector<string>> result;
        Node* curr = root;

        for (char c : searchWord) {
            if (curr) curr = curr->child[c - 'a'];
            
            if (!curr) result.push_back({});
            else result.push_back({curr->suggestions});
        }

        return result;
    }
};