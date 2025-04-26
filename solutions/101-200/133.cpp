/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
  public:
    Node *cloneGraph(Node *node) {
        if (!node) {
            return nullptr;
        }
        std::unordered_map<Node *, Node *> map;
        std::unordered_set<Node *> visit_map;
        std::queue<Node *> q;
        q.push(node);
        while (!q.empty()) {
            Node *n = q.front();
            if (visit_map.find(n) == visit_map.end()) {
                // not visited
                Node *new_node = nullptr;
                if (map.find(n) != map.end()) {
                    new_node = map[n];
                } else {
                    new_node = new Node();
                }
                new_node->val = n->val;
                for (auto &nn : n->neighbors) {
                    Node *nnn = nullptr;
                    if (map.find(nn) == map.end()) {
                        nnn = new Node();
                        map[nn] = nnn;
                    } else {
                        nnn = map[nn];
                    }
                    new_node->neighbors.push_back(nnn);
                    if (visit_map.find(nn) == visit_map.end()) {
                        q.push(nn);
                    }
                }
                visit_map.insert(n);
                map[n] = new_node;
            }
            q.pop();
        }
        return map[node];
    }
};