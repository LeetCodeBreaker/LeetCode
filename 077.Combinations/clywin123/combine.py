import copy
class Solution:
    # @param {integer} n
    # @param {integer} k
    # @return {integer[][]}
    def _combine(self,n,k,which,result,answer):
        if(which==k):
            answer.append(copy.deepcopy(result))
            return 
        else:
            for i in range(n):
                if((i+1) not in result):
                    if(len(result)==0 or(len(result)>0 and (i+1)>result[-1])):
                        result.append(i+1)
                        self._combine(n,k,which+1,result,answer)
                        result.pop()
        return 

    def combine(self, n, k):
        answer = []
        self._combine(n,k,0,[],answer)
        return answer
