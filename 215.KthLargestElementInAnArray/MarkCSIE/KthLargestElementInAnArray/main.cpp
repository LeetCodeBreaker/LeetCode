#include <iostream>
#include <vector>

class Solution
{
public:
  int findKthLargest(std::vector<int> nums, const int& k)
  {
    int index = quickSelect(nums, 0, nums.size() - 1, nums.size() - k + 1);
    return nums[index];
  }

protected:
  int quickSelect(std::vector<int>& nums, const int& left, const int& right, const int& k)
  {
    int pivot = nums[right];
    int left_i = left;
    for (int i = left; i < right; ++i)
    {
      if (nums[i] < pivot)
      {
        std::swap(nums[i], nums[left_i]);
        ++left_i;
      }
    }
    std::swap(nums[right], nums[left_i]);

    int left_size = left_i - left;
    if (left_size == k - 1)
    {
      return left_i;
    }
    else if (left_size > k - 1)
    {
      return quickSelect(nums, left, left_i - 1, k);
    }
    else
    {
      return quickSelect(nums, left_i + 1, right, k-left_size-1);
    }
  }
};

int main()
{
  Solution solution;
  std::vector<int> test = {3, 2, 1, 5, 6, 4};
  std::cout << solution.findKthLargest(test, 2) << std::endl;
  return 0;
}
