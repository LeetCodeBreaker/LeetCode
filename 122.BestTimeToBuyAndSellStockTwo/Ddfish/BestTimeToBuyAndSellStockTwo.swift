class Solution {
    func maxProfit(_ prices: [Int]) -> Int {
        
        if( prices.count == 0){return 0}
        
        var profit = 0
        for i in 1..<prices.count {
           let x = prices[i] - prices[i-1]
           if(x > 0){ profit += x}
        }
      
        return profit
    }
}
