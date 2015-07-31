class Solution:
    # @param {integer[][]} matrix
    # @param {integer} target
    # @return {boolean}
    def searchMatrix(self, matrix, target):
        left = 0
        right = len(matrix)-1
        if(type(matrix[0])==int):
            if(target in matrix):
                return True
            else:
                return False
        tmp = len(matrix[0])/2
        while(left<right):
            mid = (left+right)/2
            if(matrix[mid][tmp]>target):
                right = mid-1
            elif(matrix[mid][tmp]<target):
                left = mid+1
            else:
                return True
        for i in range(len(matrix[0])):
            if(left-1>0):
                if(matrix[left-1][i]==target):
                    return True
            if(matrix[left][i]==target):
                return True
            if(left+1<len(matrix)):
                if(matrix[left+1][i]==target):
                    return True
        return False
        
