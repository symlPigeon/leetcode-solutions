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
    vector<double> averageOfLevels(TreeNode *root) {
        if (!root) {
            return std::vector<double>();
        }
        std::vector<double> ans;
        std::queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            double sum = 0;
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                TreeNode *front = q.front();
                sum += front->val;
                if (front->left) {
                    q.push(front->left);
                }
                if (front->right) {
                    q.push(front->right);
                }
                q.pop();
            }
            ans.push_back(sum / sz);
        }
        return ans;
    }
};