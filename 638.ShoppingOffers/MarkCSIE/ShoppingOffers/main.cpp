#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <limits>

using std::vector;

class Solution
{
public:
  int shoppingOffers(const vector<int> &price, const vector<vector<int>> &special, const vector<int>& needs)
  {
    std::unordered_map<int, int> memo;
    return recursive(price, special, needs, memo);
  }

protected:
  int recursive(const vector<int> &price, const vector<vector<int>> &special, const vector<int> &needs, std::unordered_map<int, int> &memo)
  {
    int needs_int = 0;
    for (size_t i = 0; i < needs.size(); ++i)
    {
      needs_int += needs[i] * std::pow(10, i);
    }
    if (memo.find(needs_int) != memo.end())
    {
      return memo[needs_int];
    }

    int min = std::numeric_limits<int>::max();
    for (size_t i = 0; i < special.size(); ++i)
    {
      bool buy = true;
      std::vector<int> post_needs = needs;
      for (size_t j = 0; j < special[i].size() - 1; ++j)
      {
        post_needs[j] -= special[i][j];
        if (post_needs[j] < 0)
        {
          buy = false;
          break;
        }
      }
      if (buy)
      {
        const int cost = special[i].back();
        const int total_cost = cost + recursive(price, special, post_needs, memo);
        min = std::min(min, total_cost);
      }
    }

    int no_special = 0;
    for (size_t i = 0; i < price.size(); ++i)
    {
      no_special += price[i] * needs[i];
    }

    memo[needs_int] = std::min(min, no_special);
    return memo[needs_int];
  }
};

int main()
{
  Solution solution;
  std::cout << solution.shoppingOffers({2, 5}, {{3, 0, 5}, {1, 2, 10}}, {3, 2}) << std::endl;
}
