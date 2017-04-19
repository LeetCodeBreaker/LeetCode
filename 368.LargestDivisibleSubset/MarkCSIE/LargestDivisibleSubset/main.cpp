#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
  std::vector<int> largestDivisibleSubset(std::vector<int> nums)
  {
    std::sort(nums.begin(), nums.end());

    std::vector<unsigned int> O(nums.size(), 0);
    std::vector<size_t> parent(nums.size(), 0);

    unsigned int max = 0;
    size_t max_index = 0;

    for (int i = nums.size() - 1; i >= 0; --i)
    {
      for (size_t j = i; j < nums.size(); ++j)
      {
        if (nums[j] % nums[i] == 0 && O[i] < 1 + O[j])
        {
          O[i] = 1 + O[j];
          parent[i] = j;

          if (O[i] > max)
          {
            max = O[i];
            max_index = i;
          }
        }
      }
    }

    std::vector<int> answer;
    for (unsigned int i = 0; i < max; ++i)
    {
      answer.push_back(nums[max_index]);
      max_index = parent[max_index];
    }

    return answer;
  }
};

int main()
{
  Solution solution;
  for (const int &i : solution.largestDivisibleSubset({1,2,3}))
  {
    std::cout << i << std::endl;
  }
  return 0;
}
