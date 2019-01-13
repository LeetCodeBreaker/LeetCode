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
var zigzagLevelOrder = function(root) {
    const result = [];
    if (!root) return result;
    result.push([root]);
    for (let i = 0; i < result.length; i++) {
        result[i + 1] = [];
        for (let j = 0; j < result[i].length; j++) {
            if (result[i][j].left) result[i + 1].push(result[i][j].left);
            if (result[i][j].right) result[i + 1].push(result[i][j].right);
        }
        if (!result[i + 1].length) {
            result.pop();
        }
    }
    return result.map((arr, index) => {
        const a = arr.map(n => n.val);
        return index % 2 === 0 ? a : a.reverse();
    })
};
