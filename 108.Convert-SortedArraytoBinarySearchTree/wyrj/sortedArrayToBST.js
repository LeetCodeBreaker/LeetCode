/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {number[]} nums
 * @return {TreeNode}
 */
var sortedArrayToBST = function(nums) {
    const f = (leftIndex, rightIndex) => {
        if (leftIndex > rightIndex) return null;
        const mid = Math.ceil((leftIndex + rightIndex) / 2);
        const root = new TreeNode(nums[mid]);
        root.left = f(leftIndex, mid - 1);
        root.right = f(mid + 1, rightIndex);
        return root;
    }
    return f(0, nums.length - 1);
};
