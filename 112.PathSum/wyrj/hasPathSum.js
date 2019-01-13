/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @param {number} sum
 * @return {boolean}
 */
var hasPathSum = function(root, sum) {
    if (!root) return false;
    const remain = sum - root.val;
    if (!root.left && !root.right) return remain === 0;
    return hasPathSum(root.left, remain) || hasPathSum(root.right, remain);
};
