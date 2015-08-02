
class Solution:
    # @param {TreeNode} root
    # @return {integer[][]}
    def levelOrder(self, root):
        if(not root):
            return []
        visit = [root]
        answer = []
        while(visit):
            answer.append([i.val for i in visit])
            newvisit = []
            for node in visit:
                if(node.left!=None):
                    newvisit.append(node.left)
                if(node.right!=None):
                    newvisit.append(node.right)
            visit = newvisit[:]

        return answer
