/* 524ms */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int queueLen = 0;
void swap(struct ListNode* queue[], int a, int b) {
    if (0 >= a || a > queueLen || 0 >= b || b > queueLen) {
        return ;
    }
    struct ListNode* temp = queue[a];
    queue[a] = queue[b];
    queue[b] = temp;
}
void push(struct ListNode* queue[], struct ListNode* node) {
    if (NULL == node) {
        return ;
    }
    queueLen++;
    queue[queueLen] = node;
    int index = queueLen, parentIndex = index >> 1;
    while (1 < index) {
        if (queue[index]->val >= queue[parentIndex]->val) {
            break;
        }
        swap(queue, index, parentIndex);
        index = parentIndex;
        parentIndex = index >> 1;
    }
}
struct ListNode* pop(struct ListNode* queue[]) {
    if (0 >= queueLen) {
        return NULL;
    }
    struct ListNode* ret = queue[1];
    queue[1] = queue[queueLen];
    queueLen--;
    int index = 1, childIndex = 2;
    while(queueLen >= childIndex) {
        if (queueLen > childIndex && queue[childIndex]->val > queue[childIndex + 1]->val) {
            childIndex++;
        }
        if (queue[index]->val <= queue[childIndex]->val) {
            break;
        }
        swap(queue, index, childIndex);
        index = childIndex;
        childIndex = index << 1;
    }
    return ret;
}
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    struct ListNode* head = NULL, *curr = NULL, *queue[10000], *next;
    int i;
    for (i = 0; i < listsSize; i++) {
        push(queue, lists[i]);
    }
    next = pop(queue);
    while(NULL != next) {
        if (NULL == head) {
            head = next;
            curr = next;
        } else {
            curr->next = next;
            curr = next;
        }
        push(queue, next->next);
        next = pop(queue);
    }
    return head;
}