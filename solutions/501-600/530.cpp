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
    int getMinimumDifference(TreeNode *root) {
        dfs(root);
        int min = 2147483647;
        for (int i = 0; i < this->vec.size() - 1; i++) {
            int sub = this->vec[i + 1] - this->vec[i];
            if (sub < min) {
                min = sub;
            }
        }
        return min;
    }
};