#include <iostream>
#include <vector>

class NumMatrix
{
private:
  std::vector<std::vector<int>> matrix_;
  std::vector<std::vector<int>> sum_map_;
public:
  NumMatrix(std::vector<std::vector<int>> matrix) : matrix_(matrix), sum_map_(matrix_)
  {
    for (unsigned int i = 0; i < matrix_.size(); i++)
    {
      for (unsigned int j = 0; j < matrix_[0].size(); j++)
      {
        int up = 0;
        if (i >= 1)
        {
          up = sum_map_[i-1][j];
        }

        int left = 0;
        if (j >= 1)
        {
          left = sum_map_[i][j-1];
        }

        int left_up = 0;
        if (i >= 1 && j >= 1)
        {
          left_up = sum_map_[i-1][j-1];
        }

        sum_map_[i][j] = matrix_[i][j] + up + left - left_up;
      }
    }
  }

  int sumRegion(int row1, int col1, int row2, int col2)
  {
    int up = 0;
    if (row1 - 1 >= 0)
    {
      up = sum_map_[row1-1][col2];
    }

    int left = 0;
    if (col1 - 1 >= 0)
    {
      left = sum_map_[row2][col1-1];
    }

    int left_up = 0;
    if (row1 - 1 >= 0 && col1 - 1 >= 0)
    {
      left_up = sum_map_[row1-1][col1-1];
    }

    return sum_map_[row2][col2] - left - up + left_up;
  }
};

int main()
{
  std::vector<std::vector<int>> matrix = {{3, 0, 1, 4, 2}, {5, 6, 3, 2, 1}, {1, 2, 0, 1, 5}, {4, 1, 0, 1, 7}, {1, 0, 3, 0, 5}};
  NumMatrix test(matrix);
  std::cout << test.sumRegion(2, 1, 4, 3) << std::endl;
  return 0;
}
