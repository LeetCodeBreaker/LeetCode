/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    let benefit = 0;
    for (let i = 1; i < prices.length; i++) {
        const delta = prices[i] - prices[i - 1];
        if (delta > 0) benefit += delta;
    }
    return benefit;
};
