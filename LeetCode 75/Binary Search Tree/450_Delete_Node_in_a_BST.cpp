#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    TreeNode* findMin(TreeNode* root) {
        while (root->left) root = root->left;
        return root;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;

        if (key < root->val)
            root->left = deleteNode(root->left, key);
        else if (key > root->val)
            root->right = deleteNode(root->right, key);
        else {
            if (!root->left && !root->right) {
                delete root;
                return nullptr;
            }

            else if (!root->left) {
                TreeNode* new_root = root->right;
                delete root;
                return new_root;
            }
            else if (!root->right) {
                TreeNode* new_root = root->left;
                delete root;
                return new_root;
            }

            else {
                TreeNode* new_root = findMin(root->right);
                root->val = new_root->val;
                root->right = deleteNode(root->right, new_root->val);
            }
        }

        return root;
    }
};