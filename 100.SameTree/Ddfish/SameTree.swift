
public class TreeNode {
    public var val: Int
    public var left: TreeNode?
    public var right: TreeNode?
    public init(_ val: Int) {
        self.val = val
        self.left = nil
        self.right = nil
    }
}

class Solution {
    func isSameTree(_ p: TreeNode?, _ q: TreeNode?) -> Bool {
        if p == nil && q == nil {
            return true
        }
        guard let p = p else {
            return false
        }
        guard let q = q else {
            return false
        }
        
        return p.val == q.val && isSameTree(p.left,q.left) && isSameTree(p.right,q.right)
        
    }
}
