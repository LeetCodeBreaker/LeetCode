#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
  void rotate(std::vector<std::vector<int>>& matrix)
  {
    std::reverse(matrix.begin(), matrix.end());
    for (size_t i = 0; i < matrix.size(); ++i)
    {
      for (size_t j = i + 1; j < matrix[i].size(); ++j)
      {
        std::swap(matrix[i][j], matrix[j][i]);
      }
    }
  }
};

int main()
{
  Solution solution;
  std::vector<std::vector<int>> test1 = {{1, 2, 3},
                                         {4, 5, 6},
                                         {7, 8, 9}};
  solution.rotate(test1);
  for (const std::vector<int>& row : test1)
  {
    for (const int& i : row)
    {
      std::cout << i << " ";
    }
    std::cout << std::endl;
  }
  return 0;
}
