
function ListNode(val) {
    this.val = val;
    this.next = null;
}

/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var sortList = function(head) {
	let len = 0;
	let curr = head;
	while (curr) {
		len += 1;
		curr = curr.next;
	}
	if (len <= 1) {
		return head;
	}

	let pre = null;
	curr = head;
	for (let i = 0; i < Math.ceil(len / 2); i++) {
		pre = curr;
		curr = curr.next;
	}

	pre.next = null;

	let newHead = sortList(head);
	let newHead2 = sortList(curr);
	if (newHead.val > newHead2.val) {
		[newHead, newHead2] = [newHead2, newHead];
	}
	curr = newHead;
	let n = newHead.next;
	let n2 = newHead2;
	newHead.next = newHead2;

	while (n && n2) {
		if (n.val <= n2.val) {
			curr.next = n;
			curr = n;
			n = n.next;
			curr.next = n2;
		} else {
			curr.next = n2;
			curr = n2;
			n2 = n2.next;
			curr.next = n;
		}
	}
	return newHead;
};

const n = new ListNode(4);
let curr = n;
[2, 3, 1].forEach(v => {
	curr.next = new ListNode(v);
	curr = curr.next;
});

sortList(n);
