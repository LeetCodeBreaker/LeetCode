
// Definition for a Node.
function Node(val, next, random) {
   this.val = val;
   this.next = next;
   this.random = random;
};


/**
 ** @param {Node} head
 ** @return {Node}
 **/
var copyRandomList = function(head) {
	const iterator = (callback) => {
		let curr = head;
		while (curr !== null) {
			callback(curr);
			curr = curr.next;
		}
	};

	const map = new Map();
	iterator((node) => {
		node.copy = new Node(node.val, null, null);
	});

	iterator((node) => {
		if (node.next) {
			node.copy.next = node.next.copy;
		}
		if (node.random) {
			node.copy.random = node.random.copy;
		}
	});

	const copy = head ? head.copy : null;
	iterator((node) => {
		delete node.copy;
	});

	return copy;
};

copyRandomList(new Node(7, null, null));
