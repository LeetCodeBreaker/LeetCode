#include <iostream>
#include <limits>
#include <vector>

class Solution
{
public:
  int numSquares(int n)
  {
    // DP
    std::vector<unsigned int> OPT(n + 1, std::numeric_limits<unsigned int>::max());
    OPT[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
      for (int j = 1; j*j <= i; ++j)
      {
        OPT[i] = std::min(OPT[i], 1 + OPT[i - (j * j)]);
      }
    }
    return OPT.back();
  }
};

int main()
{
  Solution solution;
  std::cout << solution.numSquares(5) << std::endl;
  return 0;
}
