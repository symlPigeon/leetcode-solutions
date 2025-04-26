/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
  public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        std::vector<ListNode *> vec;
        while (head) {
            vec.push_back(head);
            head = head->next;
        }
        if (vec.size() == 1) {
            return nullptr;
        }
        int idx = vec.size() - n;
        if (idx == 0) {
            return vec[1];
        }
        if (idx == vec.size() - 1) {
            vec[idx - 1]->next = nullptr;
            return vec[0];
        }
        vec[idx - 1]->next = vec[idx + 1];
        return vec[0];
    }
};