#include <iostream>
#include <vector>

class Solution
{
public:
  std::vector<int> findDuplicates(std::vector<int>& nums)
  {
    std::vector<int> answer;
    for (size_t i = 0; i < nums.size(); ++i)
    {
      if (nums[std::abs(nums[i])-1] < 0)
      {
        answer.push_back(std::abs(nums[i]));
      }
      else
      {
        nums[std::abs(nums[i])-1] = -nums[std::abs(nums[i])-1];
      }
    }

    // recover the input
    for (int &i : nums)
    {
      i = std::abs(i);
    }

    return answer;
  }
};

int main()
{
  Solution solution;
  std::vector<int> test = {4, 3, 2, 7, 8, 2, 3, 1};
  for (const int &i : solution.findDuplicates(test))
  {
    std::cout << i << std::endl;
  }

  return 0;
}
