class Solution:
    # @param {string} s
    # @return {integer}
    def romanToInt(self, s):
        roman={'I':1,'IV':4,'V':5,'IX':9,'X':10,'XL':40,"L":50
                ,'XC':90,'C':100,'CD':400,'D':500,'CM':900,'M':1000}
        pas = False
        answer = 0
        for i in range(len(s)):
            if(pas):
                pas = False
                continue
            if(i+1<len(s) and roman.has_key(s[i:i+2])):
                    pas = True
                    answer+=roman[s[i:i+2]]
            else:
                answer+=roman[s[i]]
            
        return answer
