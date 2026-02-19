/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int solve(TreeNode* root, unordered_map<TreeNode*, int>& dp){
        if(root == NULL) return 0;

        if(dp.find(root) != dp.end()){
            return dp[root];
        }

        int a = 0, b = 0;

        if(root->left){
            a = solve(root->left->left, dp) +
                solve(root->left->right, dp);
        }

        if(root->right){
            b = solve(root->right->left, dp) +
                solve(root->right->right, dp);
        }

        int take = root->val + a + b;
        int nottake = solve(root->left, dp) +
                      solve(root->right, dp);

        dp[root] = max(take, nottake);
        return dp[root];
    }

    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int> dp;
        return solve(root, dp);
    }
};