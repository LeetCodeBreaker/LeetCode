#include <iostream>
#include <vector>
#include <limits>

class Solution
{
public:
  std::vector<std::vector<int>> updateMatrix(const std::vector<std::vector<int>>& matrix)
  {
    int rows = matrix.size();
    int cols = matrix[0].size();
    std::vector<std::vector<int>> answer(rows, std::vector<int>(cols, std::numeric_limits<int>::max() - 1));
    for (int row = 0; row < rows; ++row)
    {
      for (int col = 0; col < cols; ++col)
      {
        if (matrix[row][col] == 0)
        {
          answer[row][col] = 0;
        }
        else
        {
          int top = std::numeric_limits<int>::max() - 1;
          if (row - 1 >= 0)
          {
            top = answer[row-1][col];
          }
          answer[row][col] = std::min(answer[row][col], top + 1);
          int left = std::numeric_limits<int>::max() - 1;
          if (col - 1 >= 0)
          {
            left = answer[row][col-1];
          }
          answer[row][col] = std::min(answer[row][col], left + 1);
        }
      }
    }

    for (int row = rows-1; row >= 0; --row)
    {
      for (int col = cols-1; col >= 0; --col)
      {
        int down = std::numeric_limits<int>::max() - 1;
        if (row + 1 < rows)
        {
          down = answer[row+1][col];
        }
        answer[row][col] = std::min(answer[row][col], down + 1);
        int right = std::numeric_limits<int>::max() - 1;
        if (col + 1 < cols)
        {
          right = answer[row][col+1];
        }
        answer[row][col] = std::min(answer[row][col], right + 1);
      }
    }
    return answer;
  }
};

int main()
{
  Solution solution;
  std::vector<std::vector<int>> answer = solution.updateMatrix({{0, 0, 0}, {0, 1, 0}, {1, 1, 1}});

  for (size_t row = 0; row < answer.size(); ++row)
  {
    for (size_t col = 0; col < answer[0].size(); ++col)
    {
      std::cout << answer[row][col] << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}
