/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public var val: Int
 *     public var left: TreeNode?
 *     public var right: TreeNode?
 *     public init(_ val: Int) {
 *         self.val = val
 *         self.left = nil
 *         self.right = nil
 *     }
 * }
 */
class Solution {
    func sumOfLeftLeaves(_ root: TreeNode?) -> Int {
        if root == nil {
            return 0
        }
        if let left = root?.left{
            if left.left == nil && left.right == nil {
                return left.val + sumOfLeftLeaves(root?.right)
            }
        }
        return sumOfLeftLeaves(root?.left) + sumOfLeftLeaves(root?.right)
    }
}
