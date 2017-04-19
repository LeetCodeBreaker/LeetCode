#include <iostream>
#include <vector>

class Solution {
public:
  unsigned int maximalSquare(const std::vector<std::vector<char>>& matrix)
  {
    if (matrix.size() == 0)
    {
      return 0;
    }

    // DP
    std::vector <unsigned int> O(matrix[0].size(), 0);
    unsigned int left_up = 0;
    unsigned int max = 0;

    for (size_t row = 0; row < matrix.size(); ++row)
    {
      for (size_t col = 0; col < matrix[0].size(); ++col)
      {
        unsigned int temp_left_up = O[col];
        if (col == 0)
        {
          O[col] = matrix[row][col] - '0';
        }
        else
        {
          if (matrix[row][col] == '1')
          {
            O[col] = std::min(O[col-1], O[col]);
            O[col] = std::min(left_up, O[col]);
            O[col]++;
          }
          else
          {
            O[col] = 0;
          }
        }
        left_up = temp_left_up;
        max = std::max(max, O[col]);
      }
    }
    return max * max;
  }
};

int main()
{
  Solution solution;
  std::vector<std::vector<char>> test = {
    {'1', '0', '1', '0', '0'},
    {'1', '0', '1', '1', '1'},
    {'1', '1', '1', '1', '1'},
    {'1', '0', '0', '1', '0'},
  };
  std::cout << solution.maximalSquare(test) << std::endl;
  return 0;
}
