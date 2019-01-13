/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {number[]} inorder
 * @param {number[]} postorder
 * @return {TreeNode}
 */
var buildTree = function(inorder, postorder) {
    if (!inorder.length) return null;
    const root = new TreeNode(postorder[postorder.length - 1]);
    const index = inorder.indexOf(root.val);
    root.left = buildTree(inorder.slice(0, index), postorder.slice(0, index));
    root.right = buildTree(inorder.slice(index + 1), postorder.slice(index, postorder.length - 1));
    return root;
};
