/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[]}
 */
var rightSideView = function(root) {
  if (!root) {
    return [];
  }
  const ans = [];
  let queue = [root];
  while (queue.length) {
    ans.push(queue[queue.length - 1].val);
    const newQueue = [];
    for (const n of queue) {
      if (n.left) {
        newQueue.push(n.left);
      }
      if (n.right) {
        newQueue.push(n.right);
      }
    }
    queue = newQueue;
  }
  return ans;
};
