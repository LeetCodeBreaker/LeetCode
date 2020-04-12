/**
 ** Definition for singly-linked list.
 ** function ListNode(val) {
 **     this.val = val;
 **     this.next = null;
 ** }
 **/

/**
 ** @param {ListNode} head
 ** @return {boolean}
 **/
var hasCycle = function(head) {
	let one = head;
	let two = head ? head.next : null;
	while (one && two) {
		if (one === two) {
			return true;
		}
		one = one.next;
		two = two.next ? two.next.next : null;
	}
	return false;
};
