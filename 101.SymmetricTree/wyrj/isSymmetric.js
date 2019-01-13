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
var isSymmetric = function(root) {
    const f = (lhs, rhs) => {
        if (!lhs || !rhs) return lhs === rhs;
        return lhs.val === rhs.val && f(lhs.left, rhs.right) && f(lhs.right, rhs.left);
    }
    return f(root, root);
};
