#include <iostream>
#include <vector>

class Solution
{
public:
  int rotatedDigits(const int& N)
  {
    std::vector<int> dp(N + 1, 0);
    int answer = 0;
    for (int i = 0; i <= N; ++i)
    {
      if (i < 10)
      {
        if (i == 2 || i == 5 || i == 6 || i == 9)
        {
          dp[i] = 2;
          ++answer;
        }
        else if (i == 0 || i == 1 || i == 8)
        {
          dp[i] = 1;
        }
      }
      else
      {
        int a = dp[i / 10];
        int b = dp[i % 10];
        if (a == 1 && b == 1)
        {
          dp[i] = 1;
        }
        else if (a >= 1 && b >= 1)
        {
          dp[i] = 2;
          ++answer;
        }
      }
    }
    return answer;
  }
};

int main()
{
  Solution solution;
  std::cout << solution.rotatedDigits(100) << std::endl;

  return 0;
}
