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
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> rightNodes;
        if (!root) return rightNodes;

        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        
        while (!nodeQueue.empty()) {
            int num_nodes_each_level = (int)nodeQueue.size();
            for (int i = 0; i < num_nodes_each_level; i++) {
                TreeNode* node = nodeQueue.front();
                nodeQueue.pop();

                if (i == num_nodes_each_level - 1) rightNodes.push_back(node->val);
                if (node->left) nodeQueue.push(node->left);
                if (node->right) nodeQueue.push(node->right);
            }
        }

        return rightNodes;
    }
};