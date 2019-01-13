/**
 * Definition for binary tree with next pointer.
 * function TreeLinkNode(val) {
 *     this.val = val;
 *     this.left = this.right = this.next = null;
 * }
 */

/**
 * @param {TreeLinkNode} root
 * @return {void} Do not return anything, modify tree in-place instead.
 */
var connect = function(root) {
    if (!root) return;
    let q = [root];
    let nq = [];
    while (q.length > 0) {
        for (let i = 0; i < q.length; i++) {
            q[i].next = q[i + 1] || null;
            if (q[i].left) nq.push(q[i].left);
            if (q[i].right) nq.push(q[i].right);
        }
        q = nq;
        nq = [];
    }
};
