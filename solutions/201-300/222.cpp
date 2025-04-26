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
    bool dfs(TreeNode *root, int depth, int path) {
        if (depth == 0) {
            return root != nullptr;
        }
        if (((path >> (depth - 1)) & 1) == 1) {
            return dfs(root->right, depth - 1, path);
        } else {
            return dfs(root->left, depth - 1, path);
        }
    }

    int countNodes(TreeNode *root) {
        if (!root) {
            return 0;
        }
        int max_depth = 0;
        TreeNode *ptr = root;
        // 先计算最深层数
        while (ptr) {
            max_depth++;
            ptr = ptr->left;
        }
        if (max_depth == 1) {
            return 1;
        }
        int path = (1 << (max_depth - 1)) - 1;
        int lb = 0;
        int rb = path;
        bool cond = dfs(root, max_depth - 1, rb);
        if (cond) {
            // full
            return (1 << max_depth) - 1;
        }
        path = (lb + rb) / 2;
        while (lb < rb - 1) {
            std::cout << "lb: " << lb << " rb: " << rb << std::endl;
            cond = dfs(root, max_depth - 1, path);
            if (cond) {
                lb = path;
                path = (rb + lb) / 2;
            } else {
                rb = path;
                path = (rb + lb) / 2;
            }
        }
        return (1 << (max_depth - 1)) + lb;
    }
};