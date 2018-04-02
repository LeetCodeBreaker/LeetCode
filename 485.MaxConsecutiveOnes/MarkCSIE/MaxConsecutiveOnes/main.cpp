#include <iostream>
#include <vector>

class Solution
{
public:
  int findMaxConsecutiveOnes(const std::vector<int>& nums)
  {
    int count = 0;
    int max_count = 0;
    for (const int& i : nums)
    {
      if (i == 1)
      {
        ++count;
      }
      else
      {
        max_count = std::max(max_count, count);
        count = 0;
      }
    }
    return std::max(max_count, count);
  }
};

int main()
{
  Solution solution;
  std::cout << solution.findMaxConsecutiveOnes({1, 1, 0, 1, 1, 1}) << std::endl;
  return 0;
}
