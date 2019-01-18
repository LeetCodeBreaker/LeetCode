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
var maxPathSum = function(root) {
    const f = (node) => {
        if (!node) return {s: Number.MIN_SAFE_INTEGER, i: Number.MIN_SAFE_INTEGER};
        const l = f(node.left);
        const r = f(node.right);
        const s = Math.max(l.s, r.s, node.val + l.i, node.val + r.i, node.val + l.i + r.i, node.val);
        const i = Math.max(node.val + l.i, node.val + r.i, node.val);
        return {s, i};
    }
    return f(root).s;
};
