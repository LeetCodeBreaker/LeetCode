#include <iostream>
#include <vector>

class Solution
{
public:
  int maxProfit(const std::vector<int> &prices)
  {
    int profit = 0;
    for (size_t i = 1; i < prices.size(); ++i)
    {
      profit += std::max(0, prices[i] - prices[i-1]);
    }
    return profit;
  }
};

int main()
{
  Solution solution;
  std::cout << solution.maxProfit({1, 2, 3, 4, 5}) << std::endl;
  return 0;
}
