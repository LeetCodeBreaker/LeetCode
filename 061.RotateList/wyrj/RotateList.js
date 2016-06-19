/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} k
 * @return {ListNode}
 */
var rotateRight = function(head, k) {
    if (!head) {
        return head;
    }
    var len = 1, curr = head, newHead, newTail, tail;
    while(curr.next !== null) {
        len += 1;
        curr = curr.next;
    }
    k = len - (k % len);
    if (len === k) {
        return head;
    }
    tail = curr;
    curr = head;
    len = 1;
    while(curr.next !== null) {
        if (len === k) {
            newTail = curr;
            newHead = curr.next;
        }
        len += 1;
        curr = curr.next;
    }
    tail.next = head;
    newTail.next = null;
    return newHead;
};