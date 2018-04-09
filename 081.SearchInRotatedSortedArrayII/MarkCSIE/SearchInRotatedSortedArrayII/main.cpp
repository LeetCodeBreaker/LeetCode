#include <iostream>
#include <vector>

class Solution
{
public:
  bool search(const std::vector<int>& nums, const int& target)
  {
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right)
    {
      int mid = (left + right) / 2;
      if (nums[mid] == target)
      {
        return true;
      }
      if (nums[mid] == nums[left] && nums[mid] == nums[right])
      {
        ++left;
        --right;
      }
      else if (nums[mid] >= nums[left])
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
      else
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
    return false;
  }
};

int main()
{
  Solution solution;
  std::cout << solution.search({3, 1, 3, 3, 3}, 1) << std::endl;
  return 0;
}
