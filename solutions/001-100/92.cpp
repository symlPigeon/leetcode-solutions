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
    ListNode *reverseBetween(ListNode *head, int left, int right) {
        if (left == right) {
            return head;
        }
        ListNode *ptr_start = nullptr;
        ListNode *ptr_stop = nullptr;
        ListNode *ptr_ = new ListNode(-1, head);
        ListNode *ptr = ptr_;
        ListNode *prev_ptr = nullptr;
        ListNode *ptr_pstop = nullptr;
        ListNode *next_ptr = ptr->next;
        for (int ptr_idx = 0; ptr; ptr_idx++, prev_ptr = ptr, ptr = next_ptr) {
            if (ptr_idx == left - 1) {
                ptr_start = ptr;
            }
            next_ptr = ptr->next;
            if (ptr_idx > left && ptr_idx <= right) {
                ptr->next = prev_ptr;
            }
            if (ptr_idx == right) {
                ptr_pstop = ptr;
            }
            if (ptr_idx == right + 1) {
                ptr_stop = ptr;
            }
        }
        ptr_start->next->next = ptr_stop;
        ptr_start->next = ptr_pstop;
        return ptr_->next;
    }
};