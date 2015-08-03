class Solution:
    def connect(self, root):
        if (not root):
            return
        visit = [root]
        while(visit):
            for i in range(len(visit)-1):
                visit[i].next = visit[i+1]
            newvisit = []
            for node in visit:
                if(node.left!=None):
                    newvisit.append(node.left)
                if(node.right!=None):
                    newvisit.append(node.right)
            visit = newvisit[:]

        return
