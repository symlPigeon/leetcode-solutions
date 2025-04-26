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
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode *ptr_ = new ListNode(-1, head);
        ListNode *ptr = ptr_;
        while (ptr) {
            // 从这一组的第一个节点开始
            int cnt = 0;
            ListNode *curr = ptr->next;
            ListNode *prev = ptr;
            ListNode *old_ptr = ptr;
            while (curr && cnt < k) {
                cnt++;
                prev = curr;
                curr = curr->next;
            }
            if (!curr && cnt < k) {
                // 这一组没跑完就结束了
                break;
            }
            // 考虑到某组在最后的情况，确实可能出现curr为null
            // 此时old_ptr指着这一组之前的节点
            // curr应该指着这一组之后的节点
            // 而prev指着这一组最后的节点
            ptr = ptr->next;
            for (cnt = 0; cnt < k; cnt++) {
                ListNode *next = ptr->next;
                ptr->next = curr;
                curr = ptr;
                ptr = next;
            }
            ptr = old_ptr->next;
            old_ptr->next = curr;
        }
        return ptr_->next;
    }
};