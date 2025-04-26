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
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head) {
            return head;
        }
        ListNode *ptr_ = new ListNode(-999, head);
        ListNode *prev_node = ptr_;
        while (head) {
            ListNode *ptr = head->next;
            int head_val = head->val;
            bool is_same = false;
            while (ptr && ptr->val == head_val) {
                ptr = ptr->next;
                is_same = true;
            }
            // 此时ptr应该到了下一个不一样的数字
            if (is_same) {
                prev_node->next = ptr;
            } else {
                prev_node->next = head;
                prev_node = head;
            }
            head = ptr;
        }
        return ptr_->next;
    }
};