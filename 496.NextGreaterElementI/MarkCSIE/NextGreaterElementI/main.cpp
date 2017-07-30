#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

class Solution
{
public:
  std::vector<int> nextGreaterElement(const std::vector<int> &findNums, const std::vector<int> &nums)
  {
    std::stack<int> s;
    std::unordered_map<int, int> table;
    for (const int &i : nums)
    {
      while (!s.empty() && i > s.top())
      {
        table[s.top()] = i;
        s.pop();
      }
      s.push(i);
    }

    std::vector<int> answer(findNums.size(), -1);
    for (size_t i = 0; i < answer.size(); i++)
    {
      if (table.find(findNums[i]) != table.end())
      {
        answer[i] = table[findNums[i]];
      }
    }
    return answer;
  }
};

int main()
{
  Solution solution;
  for (const int &i : solution.nextGreaterElement({4, 1, 2}, {1,3,4,2}))
  {
    std::cout << i << std::endl;
  }
  return 0;
}
