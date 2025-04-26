/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
  public:
    bool dfs(TreeNode *root, int target, int sum) {
        sum += root->val;
        return (root->left && dfs(root->left, target, sum)) ||
               (root->right && dfs(root->right, target, sum)) ||
               (!root->left && !root->right && sum == target);
    }
    bool hasPathSum(TreeNode *root, int targetSum) {
        if (!root)
            return false;
        return dfs(root, targetSum, 0);
    }
};