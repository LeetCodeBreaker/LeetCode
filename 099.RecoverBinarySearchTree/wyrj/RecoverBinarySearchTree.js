/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {void} Do not return anything, modify root in-place instead.
 */
var recoverTree = function(root) {
    let leftNode = null;
    let rightNode = null;
    let lastNode = null;
    const f = (node) => {
        if (!node) return;
        f(node.left);
        if (lastNode && lastNode.val > node.val) {
            if (!leftNode) leftNode = lastNode;
            rightNode = node;
        }
        lastNode = node;
        f(node.right);
    }
    f(root);
    if (leftNode) {
        if (!rightNode) rightNode = lastNode;
        const temp = leftNode.val;
        leftNode.val = rightNode.val;
        rightNode.val = temp;
    }
};
