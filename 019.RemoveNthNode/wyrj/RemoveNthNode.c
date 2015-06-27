/* 0ms */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode *start = head, *end = head;
    while(n--) {
        end = end->next;
    }
    if (NULL == end) {
        return (head) ? head->next : NULL;
    }
    while(NULL != end->next) {
        start = start->next;
        end = end->next;
    }
    start->next = start->next->next;
    return head;
}