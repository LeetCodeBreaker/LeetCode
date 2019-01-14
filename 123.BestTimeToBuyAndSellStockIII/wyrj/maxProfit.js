/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    let first = prices.map(p => 0);
    let priceMin = prices[0];
    for (let i = 1; i < prices.length; i++) {
        if (prices[i] < priceMin) priceMin = prices[i];
        first[i] = Math.max(first[i - 1], prices[i] - priceMin);
    }
    let second = prices.map(p => 0);
    let priceMax = prices[prices.length - 1];
    for (let i = prices.length - 2; i >= 0; i--) {
        if (prices[i] > priceMax) priceMax = prices[i];
        second[i] = Math.max(second[i + 1], priceMax - prices[i]);
    }
    let max = 0;
    for (let i = 0; i < prices.length; i++) max = Math.max(max, first[i] + second[i]);
    return max;
};
