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
    int maxDepth(TreeNode *root) {
        if (!root) {
            return 0;
        }
        int layers = 0;
        std::vector<TreeNode *> nodes;
        std::vector<TreeNode *> child_nodes;
        nodes.push_back(root);
        while (!nodes.empty()) {
            child_nodes.clear();
            for (auto &node : nodes) {
                if (node->left) {
                    child_nodes.push_back(node->left);
                }
                if (node->right) {
                    child_nodes.push_back(node->right);
                }
            }
            layers += 1;
            nodes = child_nodes;
        }
        return layers;
    }
};