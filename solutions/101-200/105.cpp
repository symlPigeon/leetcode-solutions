class Solution {
  public:
    TreeNode *buildTreeImpl(vector<int> &preorder, vector<int> &inorder,
                            int pre_l, int in_l, int sz) {
        if (sz == 0) {
            return nullptr;
        }
        // std::cout << "build node " << preorder[pre_l] << std::endl;
        // std::cout << "pre_l: " << pre_l << " in_l: " << in_l << " sz: " << sz
        // << std::endl;
        int root = preorder[pre_l];
        int root_idx = in_l;
        for (; inorder[root_idx] != root; root_idx++)
            ;
        int left_sz = root_idx - in_l;
        int right_sz = sz - left_sz - 1;
        return new TreeNode(root,
                            buildTreeImpl(preorder, inorder, pre_l + 1,
                                          root_idx - left_sz, left_sz),
                            buildTreeImpl(preorder, inorder,
                                          pre_l + left_sz + 1, root_idx + 1,
                                          right_sz));
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // 将preorder的第一个节点作为根
        if (preorder.empty()) {
            return nullptr;
        }
        return buildTreeImpl(preorder, inorder, 0, 0, preorder.size());
    }
};