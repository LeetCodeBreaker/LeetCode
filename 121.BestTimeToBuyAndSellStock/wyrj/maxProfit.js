/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    let minPrice = prices[0];
    let benefit = 0;
    for (let i = 1; i < prices.length; i++) {
        if (prices[i] < minPrice) minPrice = prices[i];
        else benefit = Math.max(benefit, prices[i] - minPrice);
    }
    return benefit;
};
