#include <iostream>
#include <vector>

class Solution
{
public:
  int jump(const std::vector<int>& nums)
  {
    int farthest = 0;
    int end = 0;
    int answer = 0;
    for (int i = 0; i < static_cast<int>(nums.size()) - 1; ++i)
    {
      farthest = std::max(farthest, i + nums[i]);
      if (i == end)
      {
        ++answer;
        end = farthest;
      }
    }
    return answer;
  }
};

int main()
{
  Solution solution;
  std::cout << solution.jump({2, 3, 1, 1, 4}) << std::endl;
  return 0;
}
