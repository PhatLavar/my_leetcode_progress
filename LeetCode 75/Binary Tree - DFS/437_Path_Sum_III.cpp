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
    int dfs(TreeNode* root, int targetSum, long long currSum, unordered_map<long long, int>& prefixSum) {
        if (!root) return 0;
        currSum += root->val;
        int count = 0;

        if (prefixSum.count(currSum - targetSum)) 
            count += prefixSum[currSum - targetSum];

        prefixSum[currSum]++;
        count += dfs(root->left, targetSum, currSum, prefixSum);
        count += dfs(root->right, targetSum, currSum, prefixSum);
        prefixSum[currSum]--;

        return count;
    }

public:
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> prefixSum;
        prefixSum[0] = 1;
        return dfs(root, targetSum, 0, prefixSum);
    }
};