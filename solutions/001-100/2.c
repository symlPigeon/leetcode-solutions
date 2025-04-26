#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {
    struct ListNode *root = (struct ListNode *)malloc(sizeof(struct ListNode));
    root->val = 0;
    root->next = 0;
    struct ListNode *CurrentNode = root;
    int inc = 0;
    // printf("%d %d %d\nstart\n",l1,l2,CurrentNode);
    while (l1 != 0 || l2 != 0 || inc) {
        // printf("%d %d %d\n",l1,l2,CurrentNode);
        if (!l1 && !l2 && inc) {
            // printf("final\n");
            inc = 0;
            CurrentNode->val = 1;
            CurrentNode->next = 0;
            break;
        } else if (l1 == 0) {
            CurrentNode->val = l2->val + inc;
            inc = 0;
            if (CurrentNode->val > 9) {
                CurrentNode->val %= 10;
                inc = 1;
            }
            l2 = l2->next;
            CurrentNode->next =
                (struct ListNode *)malloc(sizeof(struct ListNode));
        } else if (l2 == 0) {
            CurrentNode->val = l1->val + inc;
            inc = 0;
            if (CurrentNode->val > 9) {
                CurrentNode->val %= 10;
                inc = 1;
            }
            l1 = l1->next;
            CurrentNode->next =
                (struct ListNode *)malloc(sizeof(struct ListNode));
        } else {
            // printf("Normal\n");
            CurrentNode->val = l1->val + l2->val + inc;
            inc = 0;
            if (CurrentNode->val > 9) {
                CurrentNode->val %= 10;
                inc = 1;
            }
            l1 = l1->next;
            l2 = l2->next;
            CurrentNode->next =
                (struct ListNode *)malloc(sizeof(struct ListNode));
        }
        // printf("Now current node value: %d\n", CurrentNode->val);
        // printf("Now current node next node: %d\n",CurrentNode->next);
        if (l1 || l2 || inc)
            CurrentNode = CurrentNode->next;
        else
            CurrentNode->next = 0;
    }
    // printf("end.\n");
    return root;
}