
public class BestTimeToBuyAndSellStock {

    public static void main(String[] args) {
        BestTimeToBuyAndSellStock test = new BestTimeToBuyAndSellStock();
        System.out.println(test.maxProfit(new int[]{2, 1, 3, 4, 5, 3, 1, 8}));
    }

    public int maxProfit(int[] prices) {
        int maxProfit = 0;
        int length = prices.length;
        int[] minIndex = new int[length];
        if (length != 0) {
            minIndex[0] = prices[0];
            for (int i = 1; i < length; i++) {
                minIndex[i] = Math.min(minIndex[i - 1], prices[i]);
                maxProfit = Math.max(maxProfit, prices[i] - minIndex[i]);
            }
        }
        return maxProfit;
    }
}
