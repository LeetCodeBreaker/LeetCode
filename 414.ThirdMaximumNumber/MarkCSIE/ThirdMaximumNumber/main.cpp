#include <iostream>
#include <vector>
#include <set>

class Solution {
public:
  int thirdMax(const std::vector<int>& nums)
  {
    // ordered set
    std::set<int> ordered_set(nums.begin(), nums.end());
    if (ordered_set.size() < 3)
    {
      return *ordered_set.rbegin();
    }
    else
    {
      std::set<int>::reverse_iterator r_it = ordered_set.rbegin();
      r_it++;
      r_it++;
      return *r_it;
    }
  }
};

int main()
{
  Solution solution;
  std::cout << solution.thirdMax({1, 3, 2}) << std::endl;
  return 0;
}
