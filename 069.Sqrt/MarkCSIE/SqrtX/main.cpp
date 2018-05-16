#include <iostream>

class Solution
{
public:
  int mySqrt(int x)
  {
    int left = 0;
    int right = x;
    while (left <= right)
    {
      long long unsigned mid = left + (right - left) / 2;
      long long unsigned square = mid * mid;
      if (square == x)
      {
        return mid;
      }
      else if (square > x)
      {
        right = mid - 1;
      }
      else
      {
        left = mid + 1;
      }
    }
    return left - 1;
  }
};

int main()
{
  Solution solution;
  std::cout << solution.mySqrt(21) << std::endl;
  return 0;
}
