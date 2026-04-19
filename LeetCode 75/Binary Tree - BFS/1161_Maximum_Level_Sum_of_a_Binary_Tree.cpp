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
    int maxLevelSum(TreeNode* root) {
        if (!root->left && !root->right) return 1;
        int level = 1;
        int level_result = 1;
        int maxSum = root->val;
        
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);

        while(!nodeQueue.empty()) {
            int sum = 0;
            int num_nodes_each_level = (int)nodeQueue.size();
            
            for (int i = 0; i < num_nodes_each_level; i++) {
                TreeNode* node = nodeQueue.front();
                nodeQueue.pop();
            
                sum += node->val;
                if (i == num_nodes_each_level - 1) {
                    if (sum > maxSum) {
                        maxSum = sum;
                        level_result = level;
                    }
                } 

                if (node->left) nodeQueue.push(node->left);
                if (node->right) nodeQueue.push(node->right);
            }
            
            level++;
        }
        
        return level_result;
    }
};