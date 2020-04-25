/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 */
var BSTIterator = function(root) {
  this.stack = [];
  this.node = root;
  while (this.node && this.node.left) {
    this.stack.push(this.node);
    this.node = this.node.left;
  }
};

/**
 * @return the next smallest number
 * @return {number}
 */
BSTIterator.prototype.next = function() {
  const val = this.node.val;
  if (this.node.right) {
    this.node = this.node.right;
    while (this.node.left) {
      this.stack.push(this.node);
      this.node = this.node.left;
    }
  } else if (this.stack.length) {
    this.node = this.stack.pop();
  } else {
    this.node = null;
  }
  return val;
};

/**
 * @return whether we have a next smallest number
 * @return {boolean}
 */
BSTIterator.prototype.hasNext = function() {
  return this.node !== null;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * var obj = new BSTIterator(root)
 * var param_1 = obj.next()
 * var param_2 = obj.hasNext()
 */
