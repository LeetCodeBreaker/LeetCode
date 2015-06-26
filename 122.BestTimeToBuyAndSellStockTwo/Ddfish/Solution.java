public class Solution {
    public int maxProfit(int[] prices) {
        int answer = 0;
        int temp = 0 ;
        for(int i = 0 ; i < prices.length-1 ; i++){
            temp = prices[i+1] -prices[i];
            if(temp>0){
                answer+=temp;
            }
        }
        return answer;
    }
}
