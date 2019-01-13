/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
var minDepth = function(root) {
    if (!root) return 0;
    let depth = 0;
    let q = [root];
    let nq = [];
    while (q.length > 0) {
        depth++;
        for (let i = 0; i < q.length; i++) {
            if (!q[i].left && !q[i].right) return depth;
            if (q[i].left) nq.push(q[i].left);
            if (q[i].right) nq.push(q[i].right);
        }
        q = nq;
        nq = [];
    }
    return depth;
};
