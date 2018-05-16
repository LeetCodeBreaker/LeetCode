#include <iostream>
#include <vector>

class Solution
{
public:
  void sortColors(std::vector<int>& nums)
  {
    int front_i = 0;
    int back_i = nums.size() - 1;
    int i = 0;
    while (i <= back_i)
    {
      if (nums[i] == 0)
      {
        std::swap(nums[front_i], nums[i]);
        ++front_i;
        ++i;
      }
      else if (nums[i] == 2)
      {
        std::swap(nums[back_i], nums[i]);
        --back_i;
      }
      else
      {
        ++i;
      }
    }
  }
};

int main()
{
  Solution solution;
  std::vector<int> testcase1 = {2, 0, 2, 1, 1, 0};
  solution.sortColors(testcase1);
  for (const int& i : testcase1)
  {
    std::cout << i << std::endl;
  }
  return 0;
}
