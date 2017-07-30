#include <iostream>

class Solution
{
public:
  bool canIWin(const int &maxChoosableInteger, const int &desiredTotal)
  {
    // Special cases
    if (desiredTotal <= 0)
    {
      return true;
    }
    if ((maxChoosableInteger + 1) * maxChoosableInteger / 2 < desiredTotal)
    {
      return false;
    }

    // Recursion
    std::string pool_string = "";
    for (int i = 0; i < maxChoosableInteger; ++i)
    {
      pool_string += "0";
    }
    return recursive(pool_string, desiredTotal);
  }

protected:
  std::unordered_map<std::string, bool> memo;

  bool recursive(std::string pool_string, const int &desiredTotal)
  {
    if (memo.find(pool_string) != memo.end())
    {
      return memo[pool_string];
    }
    else
    {
      if (desiredTotal <= 0)
      {
        memo[pool_string] = false;
        return false;
      }
      for (size_t i = 0; i < pool_string.length(); ++i)
      {
        if (pool_string[i] == '0')
        {
          pool_string[i] = '1';
          const bool opponent_win = recursive(pool_string, desiredTotal - (i+1));
          pool_string[i] = '0';
          if (!opponent_win)
          {
            memo[pool_string] = true;
            return true;
          }
        }
      }
    }
    memo[pool_string] = false;
    return false;
  }
};

int main()
{
  Solution solution;
  std::cout << solution.canIWin(10, 11) << std::endl;
  return 0;
}
