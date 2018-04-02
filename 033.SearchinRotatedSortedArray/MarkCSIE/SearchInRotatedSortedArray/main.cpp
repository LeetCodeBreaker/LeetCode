#include <iostream>
#include <vector>

class Solution
{
public:
  int search(const std::vector<int>& nums, const int& target)
  {
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right)
    {
      int mid = (left + right) / 2;
      if (nums[mid] == target)
      {
        return mid;
      }
      if (nums[mid] >= nums[left]) // 4 5 6 7 0 1 2
      {
        if (target >= nums[left] && target < nums[mid])
        {
          right = mid - 1;
        }
        else
        {
          left = mid + 1;
        }
      }
      else // 6 7 0 1 2 4 5
      {
        if (target <= nums[right] && target > nums[mid])
        {
          left = mid + 1;
        }
        else
        {
          right = mid - 1;
        }
      }
    }
    return -1;
  }
};

int main()
{
  Solution solution;
  std::cout << solution.search({4, 5, 6, 7, 0, 1, 2}, 5) << std::endl;
  return 0;
}
