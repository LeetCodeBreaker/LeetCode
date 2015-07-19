/* 176ms */
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
var reverseKGroup = function(head, k) {
    var retHead = head, start, curr = head, prev = null, end = null, next;
    while (true) {
        var n = k - 1;
        end = curr;
        while(0 < n && null !== end) {
            n--;
            end = end.next;
        }
        if (null === end) {
            break;
        }
        start = curr;
        while (curr !== end) {
            if (null === prev) {
                retHead = curr.next;
            } else {
                prev.next = curr.next;
            }
            next = curr.next;
            curr.next = end.next;
            end.next = curr;
            curr = next;
        }
        prev = start;
        curr = prev.next;
    }
    return retHead;
};