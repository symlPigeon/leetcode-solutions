template <typename T> class Node {
  public:
    T data;
    bool visited;
    Node *prev;
    Node *next;

    Node(const T &val)
        : data(val), prev(nullptr), next(nullptr), visited(false) {
    }

    void insert_prev(Node<T> *node) {
        if (this->prev) {
            this->prev->next = node;
            node->prev = this->prev;
        }
        node->next = this;
        this->prev = node;
    }

    void insert_next(Node<T> *node) {
        if (this->next) {
            this->next->prev = node;
            node->next = this->next;
        }
        node->prev = this;
        this->next = node;
    }

    Node<T> *get_head() {
        Node<T> *ptr = this;
        while (ptr->prev) {
            ptr = ptr->prev;
        }
        return ptr;
    }

    int cnt_len() {
        this->visited = true;
        if (!this->next) {
            return 1;
        }
        return 1 + this->next->cnt_len();
    }
};

class Solution {
  public:
    int longestConsecutive(vector<int> &nums) {
        std::unordered_map<int, Node<int> *> map;
        for (auto &i : nums) {
            if (map[i]) {
                // remove duplicated value
                continue;
            }
            Node<int> *node = new Node<int>(i);
            map[i] = node;
            if (map[i - 1]) {
                map[i - 1]->insert_next(node);
            }
            if (map[i + 1]) {
                map[i + 1]->insert_prev(node);
            }
        }
        int max_length = 0;
        for (auto &kv : map) {
            Node<int> *node = kv.second;
            if (!node) {
                continue;
            }
            if (node->visited) {
                continue;
            }
            Node<int> *head = node->get_head();
            int length = head->cnt_len();
            if (length > max_length) {
                max_length = length;
            }
        }
        return max_length;
    }
};