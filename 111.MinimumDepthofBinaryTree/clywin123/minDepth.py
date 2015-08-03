class Solution:
    # @param {TreeNode} root
    # @return {integer}
    def minDepth(self, root):
        if(not root):
            return 0
        def _minDepth(root,value):
            if(not root):
                return float("inf")
            if(root.left==None and root.right==None):
                value += 1
                return value
            value+=1
            le = _minDepth(root.left,value)
            ri = _minDepth(root.right,value)
            return min(le,ri)
        return _minDepth(root,0)
