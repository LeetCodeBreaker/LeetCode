class Solution:
    # @param {integer} num
    # @return {string}
    def intToRoman(self, num):
        roman={'I':1,'IV':4,'V':5,'IX':9,'X':10,'XL':40,"L":50
                ,'XC':90,'C':100,'CD':400,'D':500,'CM':900,'M':1000}
        roman1={1:'I',4:'IV',5:'V',9:'IX',10:'X',40:'XL',50:"L"
                ,90:'XC',100:'C',400:'CD',500:'D',900:'CM',1000:'M'}
        integer=[1,4,5,9,10,40,50,90,100,400,500,900,1000]
        length = len(integer)-1
        answer = ''
        while(num>0):
            for i in range(length,-1,-1):
                if(integer[i]<=num):
                    num -= integer[i]
                    answer += roman1[integer[i]]
                    length = i
                    break
        return answer
