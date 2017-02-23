#include <iostream>
#include <vector>

class Solution {
public:
  int coinChange(const std::vector<int>& coins, const int &amount) {
    std::vector<int> values(amount + 1, -1);
    values[0] = 0;
    for (int i = 1; i <= amount; i++)
    {
      int min = -1;
      for (const int &coin : coins)
      {
        if (i - coin >= 0 && values[i - coin] != -1)
        {
          if (values[i - coin] + 1 < min || min == -1)
          {
            min = values[i - coin] + 1;
          }
        }
      }
      values[i] = min;
    }
    return values[amount];
  }
};

int main()
{
  Solution solution;
  std::cout << solution.coinChange({1, 2, 5}, 11) << std::endl;

  return EXIT_SUCCESS;
}
