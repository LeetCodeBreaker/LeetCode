#include <iostream>
#include <vector>
#include <unordered_map>

class Solution
{
public:
  int findMaxLength(const std::vector<int> &nums)
  {
    std::unordered_map<int, size_t> count2index;
    count2index[0] = 0;
    int count = 0;
    size_t max = 0;
    for (size_t i = 0; i < nums.size(); i++)
    {
      if (nums[i] == 0)
      {
        count--;
      }
      else
      {
        count++;
      }

      if (count2index.find(count) != count2index.end())
      {
        max = std::max(max, (i + 1) - count2index[count]);
      }
      else
      {
        count2index[count] = i + 1;
      }
    }
    return max;
  }
};

int main()
{
  Solution solution;
  std::cout << solution.findMaxLength({0, 1}) << std::endl;
  return 0;
}
