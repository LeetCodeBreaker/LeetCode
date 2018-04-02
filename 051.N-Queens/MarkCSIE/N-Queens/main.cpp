#include <iostream>
#include <vector>

class Solution
{
public:
  std::vector<std::vector<std::string>> solveNQueens(const int& n)
  {
    std::vector<std::vector<std::string>> answer;
    std::vector<std::string> configuration(n, std::string(n, '.'));
    recursive(answer, configuration, 0);
    return answer;

  }

  void recursive(std::vector<std::vector<std::string>>& answer, std::vector<std::string>& configuration, const int& row)
  {
    int n = configuration.size();
    if (row == n)
    {
      answer.push_back(configuration);
    }

    for (int col = 0; col < n; ++col)
    {
      if (isValid(row, col, configuration))
      {
        configuration[row][col] = 'Q';
        recursive(answer, configuration, row + 1);
        configuration[row][col] = '.';
      }
    }
  }

  bool isValid(const int& row, const int& col, const std::vector<std::string>& configuration)
  {
    int n = configuration.size();
    for (int i = 0; i < row; ++i)
    {
      if (configuration[i][col] == 'Q')
      {
        return false;
      }
    }
    for (int i = row -1, j = col - 1; i >= 0 && j >= 0; --i, --j)
    {
      if (configuration[i][j] == 'Q')
      {
        return false;
      }
    }
    for (int i = row -1, j = col + 1; i >= 0 && j < n; --i, ++j)
    {
      if (configuration[i][j] == 'Q')
      {
        return false;
      }
    }
    return true;
  }
};

int main()
{
  Solution solution;
  for (const std::vector<std::string>& v: solution.solveNQueens(4))
  {
    for (const std::string& s : v)
    {
      std::cout << s << std::endl;
    }
    std::cout << std::endl;
  }

  return 0;
}
