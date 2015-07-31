class Solution:
    # @param {integer} n
    # @return {integer[][]}
    def generateMatrix(self, n):
        if(not n):
            return []
        matrix = [[0 for i in range(n)]for i in range(n)]
        up = 0
        down = n-1
        left = 0
        right = n-1
        num = 1
        while(1):
            for i in range(left,right+1):
                matrix[up][i] = num
                num+=1
            up += 1
            if(up>down):
                break
            for i in range(up,down+1):
                matrix[i][right]= num
                num+=1
            right -=1
            if(right<left):
                break
            for i in range(right,left-1,-1):
                matrix[down][i]= num
                num+=1
            down -= 1
            if(down<up):
                break
            for i in range(down,up-1,-1):
                matrix[i][left] = num
                num +=1
            left += 1
            if(left>right):
                break
        return matrix
