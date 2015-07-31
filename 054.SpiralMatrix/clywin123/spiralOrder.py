class Solution:
    def spiralOrder(self, matrix):
        if(not matrix or type(matrix[0])==int):
            return matrix
        up = 0
        down = len(matrix)-1
        left = 0
        right = len(matrix[0])-1
        tmplist = []
        while(1):
            for i in range(left,right+1):
                tmplist.append(matrix[up][i])
            up += 1
            if(up>down):
                break
            
            for i in range(up,down+1):
                tmplist.append(matrix[i][right])
            right -=1
            if(right<left):
                break
            
            for i in range(right,left-1,-1):
                tmplist.append(matrix[down][i])
            down -= 1
            if(down<up):
                break

            for i in range(down,up-1,-1):
                tmplist.append(matrix[i][left])
            left += 1
            if(left>right):
                break

            print left,right,up,down
        return tmplist
