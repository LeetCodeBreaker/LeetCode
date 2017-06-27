#include <iostream>
#include <vector>
#include <stack>

class Solution
{
public:
  std::vector<int> nextGreaterElements(const std::vector<int> &nums)
  {
    std::vector<int> answer(nums.size(), -1);
    std::stack<size_t> index_stack;
    for (size_t i = 0; i < nums.size() * 2; i++)
    {
      while (!index_stack.empty() && nums[index_stack.top()] < nums[i % nums.size()])
      {
        answer[index_stack.top()] = nums[i % nums.size()];
        index_stack.pop();
      }
      if (i < nums.size())
      {
        index_stack.push(i);
      }
    }
    return answer;
  }
};

int main()
{
  Solution solution;
  for (const int &i : solution.nextGreaterElements({1, 2, 1}))
  {
    std::cout << i << std::endl;
  }

  return 0;
}
