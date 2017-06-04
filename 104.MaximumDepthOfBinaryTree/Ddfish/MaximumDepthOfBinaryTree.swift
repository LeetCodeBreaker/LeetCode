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
    func maxDepth(_ root: TreeNode?) -> Int {
        return privateMaxDepth(root,0)
    }
    
    private func privateMaxDepth(_ node : TreeNode?,_ depth : Int) -> Int {
        
        if node == nil {
            return depth
        }
        
        let leftDepth  = privateMaxDepth(node?.left,depth+1)
        let rightDepth = privateMaxDepth(node?.right,depth+1)
        
        return max(leftDepth,rightDepth)
    }
}
