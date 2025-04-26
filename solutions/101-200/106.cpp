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
    TreeNode *buildTreeImpl(vector<int> &inorder, vector<int> &postorder,
                            int post_l, int in_l, int sz) {
        if (sz == 0) {
            return nullptr;
        }
        // std::cout << "build node " << postorder[post_l + sz - 1] <<
        // std::endl; std::cout << "post_l: " << post_l << " in_l: " << in_l <<
        // " sz: " << sz << std::endl;
        int root = postorder[post_l + sz - 1];
        int idx = in_l;
        for (; inorder[idx] != root; idx++)
            ;
        int left_sz = idx - in_l;
        int right_sz = sz - left_sz - 1;
        return new TreeNode(
            root, buildTreeImpl(inorder, postorder, post_l, in_l, left_sz),
            buildTreeImpl(inorder, postorder, post_l + left_sz,
                          in_l + left_sz + 1, right_sz));
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // 将preorder的第一个节点作为根
        if (postorder.empty()) {
            return nullptr;
        }
        return buildTreeImpl(inorder, postorder, 0, 0, postorder.size());
    }
};