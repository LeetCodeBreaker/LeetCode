#include <iostream>
#include <vector>
#include <queue>

class Solution
{
public:
  std::vector<std::string> findRelativeRanks(const std::vector<int> &nums)
  {
    std::priority_queue<std::pair<int, int>> max_heap;
    for (size_t i = 0; i < nums.size(); i++)
    {
      max_heap.push(std::make_pair(nums[i], i));
    }

    std::vector<std::string> answer(nums.size());
    while (!max_heap.empty())
    {
      if (max_heap.size() == nums.size())
      {
        answer[max_heap.top().second] = "Gold Medal";
      }
      else if (max_heap.size() == nums.size() - 1)
      {
        answer[max_heap.top().second] = "Silver Medal";
      }
      else if (max_heap.size() == nums.size() - 2)
      {
        answer[max_heap.top().second] = "Bronze Medal";
      }
      else
      {
        answer[max_heap.top().second] = std::to_string(nums.size() - max_heap.size() + 1);
      }
      max_heap.pop();
    }

    return answer;
  }
};

int main()
{
  Solution solution;
  for (const std::string &s : solution.findRelativeRanks({5, 4, 3, 2, 1}))
  {
    std::cout << s << std::endl;
  }
  return 0;
}
