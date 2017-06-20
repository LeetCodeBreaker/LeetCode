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
    func mergeTrees(_ t1: TreeNode?, _ t2: TreeNode?) -> TreeNode? {
        
        if t1 == nil {
            return t2
        }else if t2 == nil{
            return t1
        }
        var answer = TreeNode(t1!.val+t2!.val)
        answer.left  = mergeTrees(t1?.left, t2?.left)
        answer.right = mergeTrees(t1?.right, t2?.right)
        return answer
    }
}
