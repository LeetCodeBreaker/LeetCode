#include <iostream>
#include <vector>

using std::vector;

class Solution
{
public:
  int findPaths(const int &m, const int &n, const int &N, const int &i, const int &j)
  {
    // DP
    return dp(m, n, N, i, j);

    // Recursive
    vector<vector<vector<int>>> memo(N+1, vector<vector<int>>(m, vector<int>(n, -1)));
    return recursive(memo, m, n, N, i, j);
  }
protected:
  // DP
  int dp(const int &m, const int &n, int N, const int &i, const int &j)
  {
    vector<vector<int>> steps(m+2, vector<int>(n+2, 0));
    steps[i+1][j+1] = 1;

    int answer = 0;
    while (N > 0)
    {
      vector<vector<int>> temp_steps = steps;
      for (int row = 0; row <= m+1; ++row)
      {
        for (int col = 0; col <= n+1; ++col)
        {
          long long int temp = 0;
          // up
          if (row - 1 > 0 && col != 0 && col != n+1)
          {
            temp += steps[row-1][col];
          }
          // down
          if (row + 1 < m+1 && col != 0 && col != n+1)
          {
            temp += steps[row+1][col];
          }
          // left
          if (col - 1 > 0 && row != 0 && row != m+1)
          {
            temp += steps[row][col-1];
          }
          // right
          if (col + 1 < n+1 && row != 0 && row != m+1)
          {
            temp += steps[row][col+1];
          }
          temp_steps[row][col] = temp % 1000000007;
          if (row == 0 || row == m+1 || col == 0 || col == n+1)
          {
            answer += temp_steps[row][col];
            answer %= 1000000007;
          }
        }
      }
      steps = temp_steps;
      --N;
    }
    return answer;
  }

  int recursive(vector<vector<vector<int>>> &memo,
                const int &m, const int &n, const int &N, const int &i, const int &j)
  {
    if (N < 0)
    {
      return 0;
    }
    if (i < 0 || i == m || j < 0 || j == n)
    {
      return 1;
    }

    if (memo[N][i][j] != -1)
    {
      return memo[N][i][j];
    }

    // up
    int up = recursive(memo, m, n, N-1, i-1, j);
    // down
    int down = recursive(memo, m, n, N-1, i+1, j);
    // left
    int left = recursive(memo, m, n, N-1, i, j-1);
    // right
    int right = recursive(memo, m, n, N-1, i, j+1);

    int answer = (static_cast<long long int>(up) + down + left + right) % 1000000007;
    memo[N][i][j] = answer;
    return answer;
  }
};

int main()
{
  Solution solution;
  std::cout << solution.findPaths(36, 5, 50, 15, 3) << std::endl;

}
