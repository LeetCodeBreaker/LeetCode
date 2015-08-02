class Solution:
    # @param {integer[]} nums
    # @return {TreeNode}
    def sortedArrayToBST(self, nums):
        if(len(nums)==0):
            return 
        middle = len(nums)/2
        node = TreeNode(nums[middle])
        if(middle-1>=0):
            node.left = self.sortedArrayToBST(nums[0:middle])
        if(middle+1<len(nums)):
            node.right = self.sortedArrayToBST(nums[middle+1:len(nums)])
        return node
        
