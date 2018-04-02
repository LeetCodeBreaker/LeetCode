#include <iostream>

class Solution
{
public:
  int getSum(const int& a, const int& b)
  {
    int answer = a;
    int carry = b;
    while (carry != 0)
    {
      int next_carry = (answer & carry) << 1;
      answer ^= carry;
      carry = next_carry;
    }

    return answer;
  }
};

int main()
{
  Solution solution;
  std::cout << solution.getSum(1, 2) << std::endl;
  return 0;
}
