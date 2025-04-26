class Solution {
  public:
    Node *copyRandomList(Node *head) {
        std::unordered_map<Node *, Node *> map;
        Node *new_list = new Node(-1);
        Node *ptr = new_list;
        while (head) {
            if (map[head]) {
                ptr->next = map[head];
                ptr->next->val = head->val;
            } else {
                ptr->next = new Node(head->val);
                map[head] = ptr->next;
            }
            ptr = ptr->next;
            if (head->random) {
                if (map[head->random]) {
                    ptr->random = map[head->random];
                } else {
                    ptr->random = new Node(head->random->val);
                    map[head->random] = ptr->random;
                }
            }
            head = head->next;
        }
        return new_list->next;
    }
};