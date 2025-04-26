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
    int maxPathSumImpl(TreeNode *root, int *max) {
        if (!root) {
            return -1147483648;
        }
        // 每个节点的值就是如果选择这个节点的话最大路径值
        int left_score = maxPathSumImpl(root->left, max);
        int right_score = maxPathSumImpl(root->right, max);
        int best_score = 0;
        best_score = (left_score >= 0 ? left_score : 0) + root->val +
                     (right_score >= 0 ? right_score : 0);
        if (best_score > *max) {
            *max = best_score;
        }
        return ((left_score >= right_score ? left_score : right_score) >= 0 ?
                    (left_score >= right_score ? left_score : right_score) :
                    0) +
               root->val;
    }
    int maxPathSum(TreeNode *root) {
        if (!root) {
            return 0;
        }
        int max = -1147483648;
        maxPathSumImpl(root, &max);
        return max;
    }
};