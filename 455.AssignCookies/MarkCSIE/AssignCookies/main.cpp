#include <iostream>
#include <queue>
#include <vector>

class Solution
{
public:
  int findContentChildren(const std::vector<int>& g, const std::vector<int>& s)
  {
    std::priority_queue<int, std::vector<int>, std::greater<int>> cookie_min_heap(s.begin(), s.end());
    std::priority_queue<int, std::vector<int>, std::greater<int>> children_min_heap(g.begin(), g.end());

    int answer = 0;
    while (!cookie_min_heap.empty() && !children_min_heap.empty())
    {
      if (cookie_min_heap.top() >= children_min_heap.top())
      {
        answer++;
        children_min_heap.pop();
      }
      cookie_min_heap.pop();
    }

    return answer;
  }
};

int main()
{
  Solution solution;
  std::cout << solution.findContentChildren({1, 2, 3}, {1, 1}) << std::endl;
  return 0;
}
