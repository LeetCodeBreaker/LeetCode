/* 24ms */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int carry = 0;
    int val;
    struct ListNode* ans = l1;
    struct ListNode* last;
    while(l1 != NULL && l2 != NULL) {
        val = (l1->val + l2->val + carry);
        carry = val / 10;
        val = val % 10;
        last = l1;
        last->val = val;
        l1 = l1->next;
        l2 = l2->next;
    }
    while(l1 != NULL) {
        if (0 == carry) {
            break;
        }
        val = (l1->val + carry);
        carry = val / 10;
        val = val % 10;
        last = l1;
        last->val = val;
        l1 = l1->next;
    }
    while(l2 != NULL) {
        last->next = l2;
        if (0 == carry) {
            break;
        }
        val = (l2->val + carry);
        carry = val / 10;
        val = val % 10;
        last = l2;
        last->val = val;
        l2 = l2->next;
    }
    if (1 == carry) {
        struct ListNode* addition = (struct ListNode*)malloc(sizeof(struct ListNode));
        addition->val = 1;
        addition->next = NULL;
        last->next = addition;
    }
    return ans;
}