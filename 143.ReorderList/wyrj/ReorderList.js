/**
 ** Definition for singly-linked list.
 ** function ListNode(val) {
 **     this.val = val;
 **     this.next = null;
 ** }
 **/
/**
 ** @param {ListNode} head
 ** @return {void} Do not return anything, modify head in-place instead.
 **/
var reorderList = function(head) {
	if (!head) {
		return;
	}
	let length = 0, curr = head;
	while (curr) {
		length += 1;
		curr = curr.next;
	}

	curr = head;
	for (let i = 0; i < Math.floor(length / 2); i++) {
		curr = curr.next;
	}

	let pre = null;
	while (curr) {
		const next = curr.next;
		curr.next = pre;
		pre = curr;
		curr = next;
	}

	curr = head;
	let tail = pre;
	while (tail.next) {
		const headNext = curr.next;
		const tailNext = tail.next;
		curr.next = tail;
		tail.next = headNext;
		curr = headNext;
		tail = tailNext;
	}
};
