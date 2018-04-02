#include <iostream>

class Solution
{
public:
  int minMoves(const std::vector<int>& nums)
  {
    int sum = std::accumulate(nums.begin(), nums.end(), 0);
    int min = *std::min_element(nums.begin(), nums.end());
    return sum - nums.size() * min;
  }
};

int main()
{
  Solution solution;
  std::cout << solution.minMoves({1, 2, 3}) << std::endl;
}
