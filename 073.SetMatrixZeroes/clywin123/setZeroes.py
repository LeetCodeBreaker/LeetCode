import copy
class Solution:
    # @param {integer[][]} matrix
    # @return {void} Do not return anything, modify matrix in-place instead.
    def setZeroes(self, matrix):
        row = []
        column = []
        if(type(matrix[0])==int):
            if 0 in matrix:
                matrix = [0 for i in range(len(matrix))]
            return
        else: 
            height = len(matrix)
            length = len(matrix[0])
            matrix2 = copy.deepcopy(matrix)

        for i in range(height):
            for j in range(length):
                if(matrix2[i][j]==0):
                    for m in range(height):
                        matrix[m][j]=0
                    for n in range(length):
                        matrix[i][n]=0
 
        return
