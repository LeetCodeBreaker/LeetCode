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
    func invertTree(_ root: TreeNode?) -> TreeNode? {
        
        guard let root = root else{
            return nil
        }
        let temp = invertTree(root.left)
        root.left = invertTree(root.right)
        root.right = temp
        return root
    }
  }
