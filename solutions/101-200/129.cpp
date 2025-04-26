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
    void dfs(TreeNode *root, int *sum, int value) {
        if (!root->left && !root->right) {
            // std::cout << *sum << " " << value << std::endl;
            value *= 10;
            *sum += root->val + value;
            return;
        }
        value *= 10;
        value += root->val;
        if (root->left) {
            dfs(root->left, sum, value);
        }
        if (root->right) {
            dfs(root->right, sum, value);
        }
    }
    int sumNumbers(TreeNode *root) {
        if (!root) {
            return 0;
        }
        int sum = 0;
        dfs(root, &sum, 0);
        return sum;
    }
};