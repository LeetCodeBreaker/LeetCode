/* 148ms */
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var swapPairs = function(head) {
    var retHead = head, prev = null, curr = head;
    while(curr && curr.next) {
        if (!prev) {
            retHead = curr.next;
            curr.next = retHead.next;
            retHead.next = curr;
        } else {
            prev.next = curr.next;
            curr.next = prev.next.next;
            prev.next.next = curr;
        }
        prev = curr;
        curr = curr.next;
    }
    return retHead;
};