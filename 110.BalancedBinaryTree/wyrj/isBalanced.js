/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {boolean}
 */
var isBalanced = function(root) {
    const f = (n) => {
        if (!n) return {b: true, h: 0};
        const l = f(n.left);
        const r = f(n.right);
        return {b: l.b && r.b && Math.abs(l.h - r.h) <= 1, h: Math.max(l.h, r.h) + 1};
    }
    return f(root).b;
};
