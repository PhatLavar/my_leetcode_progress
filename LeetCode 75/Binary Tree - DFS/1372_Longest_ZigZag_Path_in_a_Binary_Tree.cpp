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
    void dfs(TreeNode* root, bool wentLeft, int length, int& longest) {
        if (!root) return;
        longest = max(longest, length);

        if (wentLeft) {
            dfs(root->right, false, length + 1, longest);
            dfs(root->left, true, 1, longest);
        } else {
            dfs(root->left, true, length + 1, longest);
            dfs(root->right, false, 1, longest);
        }
    }

public:
    int longestZigZag(TreeNode* root) {
        int longest = 0;
        dfs(root, true, 0, longest);
        dfs(root, false, 0, longest);
        return longest;
    }
};