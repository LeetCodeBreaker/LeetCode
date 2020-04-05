/**
 ** Definition for a binary tree node.
 ** function TreeNode(val) {
 **     this.val = val;
 **     this.left = this.right = null;
 ** }
 **/
/**
 ** @param {TreeNode} root
 ** @return {number}
 **/
var sumNumbers = function(root) {
	const path = [];
	let value = 0;
	const dfs = (node) => {
		if (!node) {
			return;
		}
		path.push(node.val);
		if (!node.left && !node.right) {
			value += parseInt(path.join(''));
		} else {
			dfs(node.left);
			dfs(node.right);
		}
		path.pop();
	}
	dfs(root);
	return value;
};
