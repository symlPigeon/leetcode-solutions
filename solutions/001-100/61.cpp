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
    ListNode *rotateRight(ListNode *head, int k) {
        if (!head) {
            return head;
        }
        if (k == 0) {
            return head;
        }
        int cnt = 0;
        ListNode *ptr = head;
        ListNode *ptr_ = nullptr;
        while (ptr) {
            cnt += 1;
            ptr_ = ptr;
            ptr = ptr->next;
        }
        k = k % cnt;
        if (k == 0) {
            return head;
        }
        ptr_->next = head;
        for (int i = 1; i < cnt - k; i++) {
            head = head->next;
        }
        ptr = head->next;
        head->next = nullptr;
        return ptr;
    }
};