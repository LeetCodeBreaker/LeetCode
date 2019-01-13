/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[][]}
 */
var levelOrderBottom = function(root) {
    if (!root) return [];
    const result = [];
    let last = [root];
    result.push(last);
    while (last.length > 0) {
        let next = [];
        for (let j = 0; j < last.length; j++) {
            if (last[j].left) next.push(last[j].left);
            if (last[j].right) next.push(last[j].right);
        }
        result.push(next);
        last = next;
    }
    result.pop();
    return result.map(arr => {
        return arr.map(n => n.val);
    }).reverse();
};
