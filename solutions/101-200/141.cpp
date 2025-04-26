/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
  public:
    bool hasCycle(ListNode *head) {
        ListNode *ptr_fast = head;
        ListNode *ptr_slow = head;
        if (!head) {
            return false;
        }
        while (true) {
            if (!ptr_fast->next || !ptr_fast->next->next) {
                return false;
            }
            ptr_fast = ptr_fast->next->next;
            ptr_slow = ptr_slow->next;
            if (ptr_fast == ptr_slow) {
                return true;
            }
        }
    }
};