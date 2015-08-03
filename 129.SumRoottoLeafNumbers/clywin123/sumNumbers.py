class Solution:
    # @param {TreeNode} root
    # @return {integer}
    def sumNumbers(self, root):
        if(not root):
            return 0 
        visit = [(root,root.val)]
        total = 0
        while(visit):
            newvisit = []
            for node in visit:
                if(node[0].left!=None):
                    leftsum = node[1]*10+node[0].left.val
                    newvisit.append((node[0].left,leftsum))
                if(node[0].right!=None):
                    rightsum = node[1]*10+node[0].right.val
                    newvisit.append((node[0].right,rightsum))
                if(node[0].left==None and node[0].right==None):
                    total += node[1]
            visit = newvisit[:]
        return total
