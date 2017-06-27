#include <iostream>
#include <vector>

class Solution
{
public:
  std::vector<std::vector<int>> matrixReshape(const std::vector<std::vector<int>>& nums, const unsigned int &r, const unsigned int &c)
  {
    if (r * c != nums.size() * nums[0].size())
    {
      return nums;
    }

    std::vector<std::vector<int>> reshaped_matrix(r, std::vector<int>(c));
    size_t reshaped_row = 0;
    size_t reshaped_col = 0;
    for (size_t row = 0; row < nums.size(); row++)
    {
      for (size_t col = 0; col < nums[0].size(); col++)
      {
        reshaped_matrix[reshaped_row][reshaped_col] = nums[row][col];
        reshaped_col++;
        if (reshaped_col == c)
        {
          reshaped_col = 0;
          reshaped_row++;
        }
      }
    }
    return reshaped_matrix;
  }
};

int main()
{
  Solution solution;
  std::vector<std::vector<int>> answer = solution.matrixReshape({{1, 2}, {3, 4}}, 1, 4);
  for (size_t row = 0; row < answer.size(); row++)
  {
    for (size_t col = 0; col < answer[0].size(); col++)
    {
      std::cout << answer[row][col] << " ";
    }
    std::cout << std::endl;
  }
  return 0;
}
