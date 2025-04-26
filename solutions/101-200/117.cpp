/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
  public:
    Node *connect(Node *root) {
        // BFS?
        if (!root) {
            return root;
        }
        std::vector<Node *> current;
        current.push_back(root);
        while (!current.empty()) {
            std::vector<Node *> next;
            for (auto &node : current) {
                if (node->left) {
                    next.push_back(node->left);
                }
                if (node->right) {
                    next.push_back(node->right);
                }
            }
            for (int idx = 0; idx < (int)next.size() - 1; idx++) {
                next[idx]->next = next[idx + 1];
            }
            current = next;
            next.clear();
        }
        return root;
    }
};