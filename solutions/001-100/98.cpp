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
    bool isValidBST(TreeNode *root) {
        dfs(root);
        for (int i = 0; i < this->vec.size() - 1; i++) {
            if (vec[i] >= vec[i + 1]) {
                return false;
            }
        }
        return true;
    }
};