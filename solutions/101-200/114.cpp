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
    TreeNode *flattenImpl(TreeNode *root) {
        // 排除空树
        if (!root) {
            return root;
        }
        TreeNode *left_child = flattenImpl(root->left);
        TreeNode *right_child = flattenImpl(root->right);
        root->right = left_child;
        root->left = nullptr;
        TreeNode *ptr = root;
        while (ptr->right) {
            ptr = ptr->right;
        }
        ptr->right = right_child;
        return root;
    }
    void flatten(TreeNode *root) {
        flattenImpl(root);
    }
};