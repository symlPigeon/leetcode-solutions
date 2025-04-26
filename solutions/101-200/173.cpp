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

class BSTIterator {
  private:
    std::stack<TreeNode *> stk;
    TreeNode *root;

  public:
    BSTIterator(TreeNode *root) {
        this->root = root;
        this->stk = std::stack<TreeNode *>();
    }

    int next() {
        while (this->root) {
            this->stk.push(this->root);
            this->root = this->root->left;
        }
        this->root = this->stk.top();
        this->stk.pop();
        int cnt = this->root->val;
        this->root = this->root->right;
        return cnt;
    }

    bool hasNext() {
        return this->root || !this->stk.empty();
    }
};


/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */