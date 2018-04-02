#include <iostream>
#include <vector>

class Solution
{
public:
  std::vector<std::vector<int>> permute(std::vector<int>& nums)
  {
    std::vector<std::vector<int>> answer;
    recursive(nums, 0, answer);
    return answer;
  }

  void recursive(std::vector<int> nums, const size_t& begin, std::vector<std::vector<int>>& answer)
  {
    if (begin >= nums.size() - 1)
    {
      answer.push_back(nums);
      return;
    }

    for (size_t i = begin; i < nums.size(); ++i)
    {
      std::swap(nums[begin], nums[i]);
      recursive(nums, begin + 1, answer);
    }
    return;
  }
};


int main()
{
  Solution solution;
  std::vector<int> testcase1 = {1, 2, 3};
  for (const std::vector<int>& v: solution.permute(testcase1))
  {
    for (const int& i: v)
    {
      std::cout << i << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}
