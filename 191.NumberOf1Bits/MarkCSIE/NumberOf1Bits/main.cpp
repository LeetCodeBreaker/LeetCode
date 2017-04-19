#include <iostream>

class Solution
{
public:
  int hammingWeight(uint32_t n)
  {
    int count = 0;
    while (n > 0)
    {
      n &= (n - 1);
      count++;
    }
    return count;
  }
};

int main()
{
  Solution solution;
  std::cout << solution.hammingWeight(11) << std::endl;
  return 0;
}
