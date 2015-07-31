class Solution:
    # @param {integer[]} digits
    # @return {integer[]}
    def plusOne(self, digits):
        carry = True
        answer = []
        for i in range(len(digits)-1,-1,-1):
            if(carry):
                digits[i] += 1
                carry = False
                if(digits[i]>=10):
                    digits[i] %=10
                    carry = True
            answer.append(digits[i])
        if(carry):
            answer.append(1)
        return answer[::-1]
