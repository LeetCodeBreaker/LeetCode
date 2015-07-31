class Solution:
    # @param {integer} n
    # @return {string[]}
    def parent(self,n,left,right,string,answer):
        if(left==n and right ==n):
            answer.append(string)
            return
        if(left < n):
            string += "("
            self.parent(n,left+1,right,string,answer)
            string = string[:len(string)-1]
        if(right < left):
            string += ")"
            self.parent(n,left,right+1,string,answer)
            string = string[:len(string)-1]
        return 
            
    def generateParenthesis(self, n):
        if(not n):
            return []
        string = "("
        answer = []
        self.parent(n,1,0,string,answer)
        return answer
