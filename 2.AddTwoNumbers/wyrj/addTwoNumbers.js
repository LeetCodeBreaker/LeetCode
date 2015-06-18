/* 288ms */
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
var addTwoNumbers = function(l1, l2) {
    var ans = l1;
    var carry = 0;
    var curr = ans;
    var val;
    while(null !== l1 && null !== l2) {
        curr = l1;
        val = (l1.val+l2.val+carry);
        curr.val = val%10;
        carry = (10 <= val) ? 1 : 0;
        l1 = l1.next;
        l2 = l2.next;
    }
    while(null !== l1) {
        if (0 === carry) {
            break;
        }
        curr = l1;
        val = l1.val+carry;
        curr.val = val%10;
        carry = (10 <= val) ? 1 : 0;
        l1 = l1.next;
    }
    while(null !== l2) {
        curr.next = l2;
        if (0 === carry) {
            break;
        }
        curr = l2;
        val = l2.val+carry;
        curr.val = (val)%10;
        carry = (10 <= val) ? 1 : 0;
        l2 = l2.next;
    }
    if (1 === carry) {
        curr.next = new ListNode(1);
    }
    return ans;
};