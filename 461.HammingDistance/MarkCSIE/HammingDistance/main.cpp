#include <iostream>

class Solution
{
public:
  int hammingDistance(const int& x, const int& y)
  {
    int z = x ^ y;
    int answer = 0;
    while (z > 0)
    {
      answer += z & 1;
      z >>= 1;
    }
    return answer;
  }
};

int main()
{
  Solution solution;
  std::cout << solution.hammingDistance(1, 4) << std::endl;
  return 0;
}
