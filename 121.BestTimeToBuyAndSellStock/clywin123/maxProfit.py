class Solution:
    # @param {integer[]} prices
    # @return {integer}
    def maxProfit(self, prices):
        minstock =float("inf")
        answer = 0
        for i in range(len(prices)):
            if(prices[i]<minstock):
                minstock = prices[i]
            if(prices[i]-minstock>answer):
                answer = prices[i]-minstock
        return answer
