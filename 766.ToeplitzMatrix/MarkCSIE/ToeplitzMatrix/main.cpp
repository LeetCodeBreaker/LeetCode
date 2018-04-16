#include <iostream>
#include <vector>

class Solution
{
public:
  bool isToeplitzMatrix(const std::vector<std::vector<int>>& matrix)
  {
    size_t m = matrix.size();
    size_t n = matrix[0].size();
    for (size_t i = 0; i < m; ++i)
    {
      for (size_t j = 0; j < n; ++j)
      {
        if (i > 0 && j > 0 && matrix[i][j] != matrix[i-1][j-1])
        {
          return false;
        }
      }
    }
    return true;
  }
};

int main()
{
  Solution solution;
  std::cout << solution.isToeplitzMatrix({{1, 2, 3, 4},
                                          {5, 1, 2, 3},
                                          {9, 5, 1, 2}}) << std::endl;
  return 0;
}
