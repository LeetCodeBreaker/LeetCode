#include <iostream>
#include <vector>
#include <stack>

class Solution
{
public:
  int maximalRectangle(const std::vector<std::vector<char>>& matrix)
  {
    if (matrix.size() == 0)
    {
      return 0;
    }

    int n = matrix[0].size();
    std::vector<int> heights(n, 0);
    int answer = 0;
    for (const std::vector<char>& row :matrix)
    {
      for (size_t i = 0; i < row.size(); ++i)
      {
        if (row[i] == '1')
        {
          ++heights[i];
        }
        else
        {
          heights[i] = 0;
        }
      }

      answer = std::max(answer, largestRectangleArea(heights));
    }
    return answer;
  }
protected:

  int largestRectangleArea(std::vector<int> heights)
  {
    std::stack<int> index;
    heights.push_back(0);
    int answer = 0;
    for (int i = 0; i < heights.size(); ++i)
    {
      while (!index.empty() && heights[index.top()] >= heights[i])
      {
        int h = heights[index.top()];
        index.pop();

        int left = index.empty() ? -1 : index.top();
        answer = std::max(answer, h * (i - left - 1));
      }
      index.push(i);
    }
    return answer;
  }
};

int main()
{
  Solution solution;
  std::cout << solution.maximalRectangle({{'1','0','1','0','0'},
                                          {'1','0','1','1','1'},
                                          {'1','1','1','1','1'},
                                          {'1','0','0','1','0'}}) << std::endl;
  return 0;
}
