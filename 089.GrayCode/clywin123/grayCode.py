class Solution:
    # @param {integer} n
    # @return {integer[]}
  def grayCode(self,n):
        if(not n):
            return [0]
        string1 = ['0','1']
        for count in range(n-1):
            string1 += string1[::-1]
            for i in range(len(string1)):
                if(i<len(string1)/2):
                    string1[i] = '0'+string1[i]
                else:
                    string1[i] = '1'+string1[i]
        answer=[int(num,2) for num in string1]
        return answer
