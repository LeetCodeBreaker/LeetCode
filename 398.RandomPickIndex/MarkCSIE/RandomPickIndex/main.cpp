#include <iostream>
#include <vector>
#include <map>

//class Solution
//{
//protected:
//  std::multimap<int, unsigned int> num_map_;
//public:
//  Solution(std::vector<int> nums)
//  {
//    for (size_t i = 0; i < nums.size(); ++i)
//    {
//      num_map_.insert(std::pair<int, unsigned int>(nums[i], i));
//    }
//  }

//  int pick(const int &target)
//  {
//    std::pair<std::multimap<int, unsigned int>::iterator, std::multimap<int,unsigned int>::iterator> ret;
//    ret = num_map_.equal_range(target);

//    unsigned int count = num_map_.count(target);
//    size_t index = rand() % count;
//    std::multimap<int, unsigned int>::iterator it = ret.first;
//    std::advance(it, index);
//    return it->second;
//  }
//};

// Reservoir Sampling
class Solution
{
protected:
  std::vector<int> nums_;
public:
  Solution(const std::vector<int> &nums) : nums_(nums)
  {

  }

  int pick(const int &target)
  {
    size_t count = 0;
    size_t index = 0;
    for (size_t i = 0; i < nums_.size(); ++i)
    {
      if (nums_[i] == target)
      {
        count++;
        if (rand() % count == 0)
        {
          index = i;
        }
      }
    }
    return index;
  }
};

int main()
{
  Solution solution({1, 2, 3, 3, 3});
  std::cout << solution.pick(3) << std::endl;
  return 0;
}
