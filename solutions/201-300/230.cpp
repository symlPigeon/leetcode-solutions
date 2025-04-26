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
  private:
    std::vector<int> vec;

  public:
    void dfs(TreeNode *root) {
        if (!root) {
            return;
        }
        dfs(root->left);
        this->vec.push_back(root->val);
        dfs(root->right);
    }
    int kthSmallest(TreeNode *root, int k) {
        dfs(root);
        return this->vec[k - 1];
    }
};