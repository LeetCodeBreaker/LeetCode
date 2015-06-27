/* 152ms */
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var mergeTwoLists = function(l1, l2) {
    var prev = null, head = null, node1 = l1, node2 = l2;
    while(null !== node1 && null !== node2) {
        if (node1.val <= node2.val) {
            if (null === prev) {
                head = node1;
                prev = node1;
            } else {
                prev.next = node1;
                prev = prev.next;
            }
            node1 = node1.next;
        }
        else {
            if (null === prev) {
                head = node2;
                prev = node2;
            } else {
                prev.next = node2;
                prev = prev.next;
            }
            node2 = node2.next;
        }
    }
    if (null !== node1) {
        if (null === prev) {
            head = node1;
        } else {
            prev.next = node1;
        }
    } else {
        if (null === prev) {
            head = node2;
        } else {
            prev.next = node2;
        }
    }
    return head;
};