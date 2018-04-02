#include <iostream>
#include <vector>
#include <cassert>

class Solution
{
public:
  int singleNonDuplicate(const std::vector<int> &nums)
  {
    // 1 1 3 3 4 4 5 8 8
    // 3 3 6 7 7 11 11
    int left_index = 0;
    int right_index = nums.size() - 1;
    while (left_index < right_index)
    {
      int mid_index = (left_index + right_index) / 2;
      if (mid_index % 2 != 0)
      {
        --mid_index;
      }
      if (nums[mid_index] == nums[mid_index+1])
      {
        left_index = mid_index + 2;
      }
      else
      {
        right_index = mid_index;
      }
    }
    assert(left_index == right_index);
    return nums[left_index];
  }
};

int main()
{
  Solution solution;
  std::cout << solution.singleNonDuplicate({1, 1, 2, 3, 3, 4, 4, 8, 8}) << std::endl;
}
