#include <iostream>
#include <vector>
#include <stack>

class Solution
{
public:
  int largestRectangleArea(std::vector<int> height)
  {
    int answer = 0;
    height.push_back(0);
    std::stack<int> index;

    for (int i = 0; i < height.size(); i++)
    {
      while (index.size() > 0 && height[index.top()] >= height[i])
      {
        int h = height[index.top()];
        index.pop();

        int left = index.size() > 0 ? index.top() : -1;
        answer = std::max(answer, h * (i - left -1));
      }
      index.push(i);
    }

    return answer;
  }
};

int main()
{
  Solution solution;
  std::cout << solution.largestRectangleArea({2, 1, 5, 6, 2, 3}) << std::endl;
  return 0;
}
