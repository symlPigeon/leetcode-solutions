/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
  private:
    std::unordered_map<TreeNode *, uint8_t> map;

  public:
    int dfs(TreeNode *root, int p, int q) {
        if (!root) {
            return 0;
        }
        int flag = 0;
        if (root->val == p) {
            flag = 1;
        }
        if (root->val == q) {
            flag = 2;
        }
        flag |= dfs(root->left, p, q) | dfs(root->right, p, q);
        this->map[root] = flag;
        return flag;
    }
    TreeNode *dfs_ans(TreeNode *root) {
        if (!root) {
            return nullptr;
        }
        if (this->map[root] != 3) {
            return nullptr;
        }
        TreeNode *ans = dfs_ans(root->left);
        if (ans) {
            return ans;
        }
        ans = dfs_ans(root->right);
        if (ans) {
            return ans;
        }
        return root;
    }
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        dfs(root, p->val, q->val);
        return dfs_ans(root);
    }
};