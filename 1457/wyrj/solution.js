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
 * @return {number}
 */
var pseudoPalindromicPaths  = function(root) {
  if (!root) {
    return 0;
  }

  const counter = new Array(10).fill(0);
  let ans = 0;
  const dfs = (node) => {
    counter[node.val] += 1;
    if (!node.left && !node.right) {
      console.log(counter);
      if (counter.filter(n => n % 2 === 1).length <= 1) {
        ans += 1;
      }
    }
    if (node.left) {
      dfs(node.left);
    }
    if (node.right) {
      dfs(node.right);
    }
    counter[node.val] -= 1;
  };

  dfs(root);
  return ans;
};

class Node {
  constructor(val) {
    this.val = val;
    this.left = null;
    this.right = null;
  }
}

const root = new Node(2);
root.left = new Node(3);
root.right = new Node(1);
root.left.left = new Node(3);
root.left.right = new Node(1);
root.right.right = new Node(1);

console.log(pseudoPalindromicPaths(root));
