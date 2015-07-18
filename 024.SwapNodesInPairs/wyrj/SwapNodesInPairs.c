/* 0ms */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode *retHead = head, *prev = NULL, *curr = head;
    while(NULL != curr && NULL != curr->next) {
        if (NULL == prev) {
            retHead = curr->next;
            curr->next = retHead->next;
            retHead->next = curr;
        } else {
            prev->next = curr->next;
            curr->next = prev->next->next;
            prev->next->next = curr;
        }
        prev = curr;
        curr = curr->next;
    }
    return retHead;
}