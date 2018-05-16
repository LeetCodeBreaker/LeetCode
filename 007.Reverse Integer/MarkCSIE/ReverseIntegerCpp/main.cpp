#include <iostream>

class Solution
{
public:
  int reverse(int x)
  {
    long long int answer = 0;
    while (x != 0)
    {
      answer = answer * 10 + x % 10;
      x /= 10;
    }
    return (static_cast<int>(answer) == answer) * answer;
  }
};

int main()
{
  Solution solution;
  std::cout << solution.reverse(123) << std::endl;
  return 0;
}
