class Solution:
    # @param {TreeNode} root
    # @param {integer} sum
    # @return {boolean}
    def hasPathSum(self, root, sum):
        def _hasPathSum(root,sum,value):
            if(not root):
                return False
            value += root.val
            if(root.left==None and root.right==None):
                if(value == sum):
                    return True
                else:
                    return False
            else:
                return _hasPathSum(root.left,sum,value) or _hasPathSum(root.right,sum,value)
        return _hasPathSum(root,sum,0) 
