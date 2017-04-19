#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

class Solution {
public:
  std::vector<int> topKFrequent(const std::vector<int>& nums, const unsigned int &k) {
    std::unordered_map<int, unsigned int> count_map;
    for (const int &i : nums)
    {
      count_map[i]++;
    }

    std::priority_queue<std::pair<unsigned int, int>> max_heap;
    for (const std::pair<int, unsigned int> &p : count_map)
    {
      max_heap.push(std::pair<unsigned int, int>(p.second, p.first));
    }

    std::vector<int> results;
    for (unsigned int i = 0; i < k; i++)
    {
      std::pair<unsigned int, int> p = max_heap.top();
      results.push_back(p.second);
      max_heap.pop();
    }
    return results;
  }
};

int main()
{
  Solution solution;
  for (const int &i : solution.topKFrequent({1,1,1,2,2,3}, 2))
  {
    std::cout << i << std::endl;
  }
  return 0;
}
