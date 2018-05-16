#include <iostream>
#include <vector>
#include <cmath>

class Solution
{
public:
  bool isValidSudoku(const std::vector<std::vector<char>>& board)
  {
    // check rows
    for (int i = 0; i < board.size(); ++i)
    {
      if (hasDuplicate(board, i, i, 0, board.size() - 1))
      {
        return false;
      }
    }

    // check cols
    for (int j = 0; j < board.size(); ++j)
    {
      if (hasDuplicate(board, 0, board.size() - 1, j, j))
      {
        return false;
      }
    }

    // check sub-regions
    int region_size = std::sqrt(board.size());
    for (int i = 0; i < region_size; ++i)
    {
      for (int j = 0; j < region_size; ++j)
      {
        if (hasDuplicate(board, i * region_size, (i+1) * region_size - 1, j * region_size, (j+1) * region_size - 1))
        {
          return false;
        }
      }
    }
    return true;
  }
protected:
  bool hasDuplicate(const std::vector<std::vector<char>>& board, const int& start_row, const int& end_row, const int& start_col, const int& end_col)
  {

    std::vector<bool> bit_set(board.size() + 1, false);
    for (int i = start_row; i <= end_row; ++i)
    {
      for (int j = start_col; j <= end_col; ++j)
      {
        if (board[i][j] != '.' && bit_set[board[i][j] - '0'])
        {
          return true;
        }
        else if (board[i][j] != '.')
        {
          bit_set[board[i][j] - '0'] = true;
        }
      }
    }
    return false;
  }
};

int main()
{
  Solution solution;
  std::cout << solution.isValidSudoku({{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                                       {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                       {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                       {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                       {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                       {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                       {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                       {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                       {'.', '.', '.', '.', '8', '.', '.', '7', '9'}}) << std::endl;
  return 0;
}
