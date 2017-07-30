#include <iostream>
#include <cmath>

class Solution
{
public:
  unsigned int findNthDigit(unsigned int n)
  {
    unsigned int digits = 1;
    unsigned int base = 1;
    while (true)
    {
      unsigned int numbers = base * 9 * digits;
      if (n <= numbers)
      {
        break;
      }
      n -= numbers;
      digits++;
      base *= 10;
    }

    unsigned int number = base + n / digits;
    if (n % digits == 0)
    {
      --number;
    }

    n %= digits;
    if (n == 0)
    {
      return number % 10;
    }
    else
    {
      return static_cast<int>(number / std::pow(10, digits - n)) % 10;
    }
  }
};

int main()
{
  Solution solution;
  std::cout << solution.findNthDigit(3) << std::endl;
  return 0;
}
