#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>

class Solution {
public:
  std::string frequencySort(const std::string &s) {
    std::unordered_map<char, unsigned int> count_map;
    for (const char &c : s)
    {
      count_map[c]++;
    }

    // Time complexity of building a heap is O(n)
    std::priority_queue<std::pair<unsigned int, char>> max_heap;
    for (const std::pair<char, unsigned int> &p : count_map)
    {
      max_heap.push(std::make_pair(p.second, p.first));
    }

    // Time complexity of deleting a whole heap is O(n)
    std::string result = "";
    while (max_heap.size() > 0)
    {
      std::pair<unsigned int, char> p = max_heap.top();
      max_heap.pop();
      for (unsigned int i = 0; i < p.first; i++)
      {
        result += p.second;
      }
    }

    return result;
  }
};

int main()
{
  Solution solution;
  std::cout << solution.frequencySort("tree") << std::endl;

  return 0;
}
