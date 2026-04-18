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
    int count(TreeNode* root, int maxVal) {
        if (!root) return 0;
        bool isGood = root->val >= maxVal;
        if (isGood) maxVal = root->val;
        return isGood + count(root->left, maxVal) + count(root->right, maxVal);
    }

public:
    int goodNodes(TreeNode* root) {
        return count(root, root->val);
    }
};