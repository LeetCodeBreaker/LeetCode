#include <iostream>
#include <vector>

class Solution {
public:

    int maxProfit(std::vector<int>& prices) {
        int n = prices.size();
        if (n == 0) {
            return 0;
        }

        std::vector<int> no(n, 0);
        std::vector<int> yes(n, 0);

        no[0] = 0;
        yes[0] = -prices[0];

        no[1] = std::max(prices[1] - prices[0], 0);
        yes[1] = std::max(-prices[0], -prices[1]);

        for (int i = 2; i < n; i++) {
            no[i] = std::max(no[i - 1], yes[i - 1] + prices[i]);
            yes[i] = std::max(yes[i - 1], no[i - 2] - prices[i]);
        }

        return no[n - 1];
    }
};

int main() {
    Solution solution;
    std::vector<int> test{1, 2, 3, 0, 2};
    std::cout << solution.maxProfit(test) << std::endl;
    return 0;
}

