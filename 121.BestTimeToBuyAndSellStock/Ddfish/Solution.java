public class Solution {
    
    public int maxProfit(int[] prices) {
        if(prices.length == 0){
            return 0;
        }
   
      int min = prices[0];
      int profit = 0;
     
       for(int i = 0 ; i < prices.length ; i++){
            if(min > prices[i]){
                min = prices[i];
            }
            int t = prices[i] - min ;
            if(t > profit){
                profit = t;
            }
        
       } 
        
        return profit;
    }
}
