#include <iostream>
#include <vector>

class Solution
{
public:
  std::vector<int> findDiagonalOrder(const std::vector<std::vector<int>> &matrix)
  {
    int m = matrix.size();
    std::vector<int> answer;
    if (m == 0)
    {
      return answer;
    }
    int n = matrix[0].size();
    answer.resize(m * n);

    bool right_up = true;
    int row = 0;
    int col = 0;
    for (size_t i = 0; i < answer.size(); i++)
    {
      answer[i] = matrix[row][col];
      if (right_up)
      {
        bool touch = false;
        ++col;
        if (col >=  n)
        {
          col = n - 1;
          touch = true;
          right_up = false;
        }

        if (touch)
        {
          row++;
        }
        else
        {
          --row;
          if (row < 0)
          {
            row = 0;
            right_up = false;
          }
        }
      }
      else
      {
        bool touch = false;
        ++row;
        if (row >=  m)
        {
          row = m - 1;
          touch = true;
          right_up = true;
        }

        if (touch)
        {
          col++;
        }
        else
        {
          --col;
          if (col < 0)
          {
            right_up = true;
            col = 0;
          }
        }
      }
    }
    return answer;
  }
};

int main()
{
  Solution solution;
  for (const int &i : solution.findDiagonalOrder({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}))
  {
    std::cout << i << " ";
  }
  std::cout << std::endl;
  return 0;
}
