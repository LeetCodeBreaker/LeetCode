class Solution:
    # @param {integer} rowIndex
    # @return {integer[]}
    def getRow(self, rowIndex):
        if(rowIndex==0):
            return [1]
        elif(rowIndex==1):
            return [1,1]
        else:
            answer = [1,1]
            for i in range(1,rowIndex):
                for j in range(len(answer)-1):
                    answer.append(answer[j]+answer[j+1])
                answer =  answer[j+2:]
                answer = [1]+answer+[1]
            return answer
        
