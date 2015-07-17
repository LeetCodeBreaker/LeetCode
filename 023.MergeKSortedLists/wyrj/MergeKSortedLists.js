/* 204ms */
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode[]} lists
 * @return {ListNode}
 */
function priorityQueue() {
    this.heap = [];
    this.heap[0] = 0;
}
priorityQueue.prototype = {
    push: function(node) {
        if (null === node) {
            return ;
        }
        this.heap[0]++;
        var index = this.heap[0];
        this.heap[index] = node;
        while(1 < index) {
            var parentIndex = index >> 1;
            var parent = this.heap[parentIndex];
            if (node.val >= parent.val) {
                break;
            } else {
                this.swap(index, parentIndex);
                index = parentIndex;
            }
        }
    },
    pop: function() {
        if (0 >= this.heap[0]) {
            return null;
        }
        var ret = this.heap[1], index = 1;
        this.heap[1] = this.heap[this.heap[0]];
        this.heap[0]--;
        var childIndex = index << 1;
        while(this.heap[0] >= childIndex) {
            if (this.heap[0] > childIndex && this.heap[childIndex].val > this.heap[childIndex + 1].val) {
                childIndex++;
            }
            if (this.heap[index].val < this.heap[childIndex].val) {
                break;
            } else {
                this.swap(index, childIndex);
                index = childIndex;
                childIndex = index << 1;
            }
        }
        return ret;
    },
    swap: function(a, b) {
        if (0 >= a || a > this.heap[0] || 0 >= b || b > this.heap[0]) {
            return ;
        }
        var temp = this.heap[a];
        this.heap[a] = this.heap[b];
        this.heap[b] = temp;
        return ;
    }
};
var mergeKLists = function(lists) {
    var head = null, curr = null, nextIndex;
    var queue = new priorityQueue();
    for (var i = 0; i < lists.length; i++) {
        queue.push(lists[i]);
    }
    while(null !== (next = queue.pop())) {
        if (null === head) {
            head = next;
            curr = next;
        } else {
            curr.next = next;
            curr = curr.next;
        }
        queue.push(next.next);
    }
    return head;
};