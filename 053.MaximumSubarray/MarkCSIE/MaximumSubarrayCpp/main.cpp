#include <iostream>
#include <vector>

class Solution
{
public:
  int maxSubArray(const std::vector<int>& nums)
  {
    int max_sum = nums[0];
    int max_sum_here = nums[0];
    for (size_t i = 1; i < nums.size(); ++i)
    {
      max_sum_here = std::max(max_sum_here + nums[i], nums[i]);
      max_sum = std::max(max_sum, max_sum_here);
    }
    return max_sum;
  }
};

int main()
{
  Solution solution;
  std::cout << solution.maxSubArray({-2, 1, -3, 4, -1, 2, 1, -5, 4}) << std::endl;
  return 0;
}
