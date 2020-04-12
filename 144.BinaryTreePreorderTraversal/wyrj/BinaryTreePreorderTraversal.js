/**
 ** Definition for a binary tree node.
 ** function TreeNode(val) {
 **     this.val = val;
 **     this.left = this.right = null;
 ** }
 **/
/**
 ** @param {TreeNode} root
 ** @return {number[]}
 **/
var preorderTraversal = function(root) {
	const result = [];
	const run = (node) => {
		if (!node) {
			return;
		}
		result.push(node.val);
		run(node.left);
		run(node.right);
	};
	run(root);
	return result;
};
