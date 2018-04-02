#include <iostream>
#include <vector>

class Solution
{
public:
  int totalNQueens(const int& n)
  {
    int answer = 0;
    std::vector<bool> col_occupancy(n, false);
    std::vector<bool> diagonal_occupancy(2 * n - 1, false);
    std::vector<bool> diagonal_occupancy2(2 * n - 1, false);
    recursive(answer, col_occupancy, diagonal_occupancy, diagonal_occupancy2, 0);
    return answer;
  }

protected:
  void recursive(int& answer, std::vector<bool>& col_occupancy, std::vector<bool>& diagonal_occupancy, std::vector<bool>& diagonal_occupancy2, const int& row)
  {
    int n = col_occupancy.size();
    if (row == n)
    {
      ++answer;
    }

    for (int col = 0; col < n; ++col)
    {
      if (!col_occupancy[col] && !diagonal_occupancy[row + col] && !diagonal_occupancy2[row + n + 1 - col])
      {
        col_occupancy[col] = true;
        diagonal_occupancy[row + col] = true;
        diagonal_occupancy2[row + n + 1 - col] = true;
        recursive(answer, col_occupancy, diagonal_occupancy, diagonal_occupancy2, row + 1);
        col_occupancy[col] = false;
        diagonal_occupancy[row + col] = false;
        diagonal_occupancy2[row + n + 1 - col] = false;
      }
    }
    return;
  }
};

int main()
{
  Solution solution;
  std::cout << solution.totalNQueens(4) << std::endl;

  return 0;
}
