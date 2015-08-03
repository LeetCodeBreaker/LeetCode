int maxProfit(int* prices, int pricesSize) {
    int profit = 0,i;
    for(i=1;i<pricesSize;i++){
        if(prices[i]>prices[i-1])
            profit +=(prices[i]-prices[i-1]);
    }
    return profit;
}
