/* 8ms */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    struct ListNode *retHead = head, *start, *curr = head, *prev = NULL, *end = NULL, *next;
    int n;
    while (true) {
        n = k - 1;
        end = curr;
        while(0 < n && NULL != end) {
            n--;
            end = end->next;
        }
        if (NULL == end) {
            break;
        }
        start = curr;
        while (curr != end) {
            if (NULL == prev) {
                retHead = curr->next;
            } else {
                prev->next = curr->next;
            }
            next = curr->next;
            curr->next = end->next;
            end->next = curr;
            curr = next;
        }
        prev = start;
        curr = prev->next;
    }
    return retHead;
}