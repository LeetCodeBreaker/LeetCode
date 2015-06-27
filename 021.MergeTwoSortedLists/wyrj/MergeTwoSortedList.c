/* 4ms */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *prev = NULL;
    struct ListNode *head = NULL;
    struct ListNode *node1 = l1, *node2 = l2;
    while(NULL != node1 && NULL != node2) {
        if (node1->val <= node2->val) {
            if (NULL == prev) {
                prev = node1;
                head = node1;
            } else {
                prev->next = node1;
                prev = prev->next;
            }
            node1 = node1->next;
        } else {
            if (NULL == prev) {
                prev = node2;
                head = node2;
            } else {
                prev->next = node2;
                prev = prev->next;
            }
            node2 = node2->next;
        }
    }
    if (NULL == prev) {
        head = (NULL != node1) ? node1 : node2;
    } else {
        prev->next = (NULL != node1) ? node1 : node2;
    }
    return head;
}