class Solution:
    # @param {integer} numRows
    # @return {integer[][]}
    def generate(self, numRows):
        pascal = [[1],[1,1]]
        if(numRows==0):
            return []
        elif(numRows==1):
            return [[1]]
        elif(numRows==2):
            return [[1],[1,1]]
        else:
            for i in range(2,numRows):
                tmplist = []
                for j in range(len(pascal[i-1])-1):
                    tmplist.append(pascal[i-1][j]+pascal[i-1][j+1])
                pascal.append([1]+tmplist+[1])
        return pascal
