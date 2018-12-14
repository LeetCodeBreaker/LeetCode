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
var deleteDuplicates = function(head) {
    let fakeHead = {next: head};
    let curr = head;
    let prev = fakeHead;
    let removeCurr = false;
    while (curr) {
        if (curr.next && curr.val === curr.next.val) {
            curr.next = curr.next.next;
            removeCurr = true;
        } else if (removeCurr) {
            prev.next = curr.next;
            removeCurr = false;
            curr = curr.next;
        } else {
            prev = curr;
            curr = curr.next;
        }
    }
    return fakeHead.next;
};
