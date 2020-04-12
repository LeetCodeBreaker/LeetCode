/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[]}
 */
var postorderTraversal = function(root) {
	const result = [];
	const run = (node) => {
		if (!node) {
			return;
		}
		run(node.left);
		run(node.right);
		result.push(node.val);
	};
	run(root);
	return result;
};
