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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        if (!root) {
            return std::vector<std::vector<int>>();
        }
        std::vector<std::vector<int>> ans;
        std::queue<TreeNode *> q;
        q.push(root);
        bool flag = false;
        while (!q.empty()) {
            std::vector<int> vals;
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                TreeNode *front = q.front();
                vals.push_back(front->val);
                if (front->left) {
                    q.push(front->left);
                }
                if (front->right) {
                    q.push(front->right);
                }
                q.pop();
            }
            if (flag) {
                std::reverse(vals.begin(), vals.end());
            }
            flag ^= true;
            ans.push_back(vals);
        }
        return ans;
    }
};