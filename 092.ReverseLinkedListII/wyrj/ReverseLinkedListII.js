/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} m
 * @param {number} n
 * @return {ListNode}
 */
var reverseBetween = function(head, m, n) {
    const fakeHead = {next: head};
    let prev = fakeHead;
    let curr = head;
    for (let i = 1; i < m; i++) {
        prev = curr;
        curr = curr.next;
    }
    for (let i = m; i < n; i++) {
        let next = curr.next;
        curr.next = next.next;
        next.next = prev.next;
        prev.next = next;
    }
    return fakeHead.next;
};
