import copy
class Solution:
    # @param {integer[][]} matrix
    # @return {void} Do not return anything, modify matrix in-place instead.
    def rotate(self, matrix):
        n = len(matrix)
        if(n<=1):
            return 
        tmp = copy.deepcopy(matrix[::-1])
        for i in range(n):
            for j in range(n):
                matrix[i][j] = tmp[j][i]
        #print matrix
        return
