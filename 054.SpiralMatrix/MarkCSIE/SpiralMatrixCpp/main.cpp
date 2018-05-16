#include <iostream>
#include <vector>
#include <array>
#include <limits>

class Solution
{
public:
  std::vector<int> spiralOrder(std::vector<std::vector<int>> matrix)
  {
    std::vector<int> answer;
    int m = matrix.size();
    if (m == 0)
    {
      return answer;
    }

    int n = matrix[0].size();
    const std::array<std::array<int, 2>, 4> steps = {{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}};

    int direction = 0;
    int row = 0;
    int col = 0;
    for (size_t i = 0; i < m * n; ++i)
    {
      answer.emplace_back(matrix[row][col]);
      matrix[row][col] = std::numeric_limits<int>::infinity();
      int next_row = row + steps[direction][0];
      int next_col = col + steps[direction][1];

      if (next_row < 0 || next_row >= m || next_col < 0 || next_col >= n || matrix[next_row][next_col] == std::numeric_limits<int>::infinity())
      {
        direction = (direction + 1) % 4;
        next_row = row + steps[direction][0];
        next_col = col + steps[direction][1];
      }
      row = next_row;
      col = next_col;
    }

    return answer;
  }
};

int main()
{
  Solution solution;
  for (const int& i : solution.spiralOrder({{1, 2, 3},
                                            {4, 5, 6},
                                            {7, 8, 9}}))
  {
    std::cout << i << " ";
  }
  return 0;
}
