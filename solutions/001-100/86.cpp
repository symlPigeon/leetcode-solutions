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
    ListNode *partition(ListNode *head, int x) {
        if (!head) {
            return head;
        }
        ListNode *head_ = new ListNode(-1000, head);
        ListNode *ptr = head;
        ListNode *ptr_ = head_;
        ListNode *split_node = nullptr;
        ListNode *split_node_prev = nullptr;
        while (ptr && ptr->val < x) {
            ptr_ = ptr;
            ptr = ptr->next;
        }
        if (!ptr) {
            return head;
        }
        split_node = ptr;
        split_node_prev = ptr_;
        while (ptr) {
            ptr_ = ptr;
            ptr = ptr->next;
            if (ptr) {
                if (ptr->val < x) {
                    ptr_->next = ptr->next;
                    split_node_prev->next = ptr;
                    split_node_prev = split_node_prev->next;
                    ptr->next = split_node;
                    ptr = ptr->next;
                }
            }
        }
        return head_->next;
    }
};