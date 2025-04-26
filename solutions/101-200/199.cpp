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
  public:
    vector<int> rightSideView(TreeNode *root) {
        if (!root) {
            return std::vector<int>();
        }
        std::vector<int> ans;
        std::queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            ans.push_back(q.back()->val);
            for (int i = 0; i < sz; i++) {
                TreeNode *front = q.front();
                if (front->left) {
                    q.push(front->left);
                }
                if (front->right) {
                    q.push(front->right);
                }
                q.pop();
            }
        }
        return ans;
    }
};