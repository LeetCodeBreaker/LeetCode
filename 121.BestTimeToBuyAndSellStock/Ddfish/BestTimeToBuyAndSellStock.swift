class Solution {
    func maxProfit(_ prices: [Int]) -> Int {
    
       if(prices.count == 0){
            return 0;
        }
   
        var min = prices[0];
        var profit = 0;
     
        for price in prices{
            if(min > price){
                min = price;
            }else if(price - min > profit){
                profit = price - min;
            }
        
       } 
        
        return profit;
        
    }
}
