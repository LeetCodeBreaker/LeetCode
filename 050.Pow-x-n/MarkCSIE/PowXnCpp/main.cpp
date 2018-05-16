#include <iostream>

class Solution
{
public:
  double myPow(double x, const int& n)
  {
    long long int power = n;
    if (n < 0)
    {
      x = 1 / x;
      power = -power;
    }
    double answer = 1.0;

    while (power > 0)
    {
      if (power & 1)
      {
        answer *= x;
      }
      power >>= 1;
      x *= x;
    }
    return answer;
  }
};

int main()
{
  Solution solution;
  std::cout << solution.myPow(2.0, 10) << std::endl;
  return 0;
}
