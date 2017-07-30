#include <iostream>

class Solution
{
public:
  // 0 1 2 3 4 5 6 7 8 9 10 11 12 ...  18 19 20 21 ... 27 28
  // 0 1 2 3 4 5 6 7 8 9  1  2  3 ...   9  1  2  3 ...  9  1
  int addDigits(const int &num)
  {
    if (num == 0)
    {
      return 0;
    }
    int answer = num % 9;
    if (answer == 0)
    {
      return 9;
    }
    else
    {
      return answer;
    }
  }
};

int main()
{
  Solution solution;
  std::cout << solution.addDigits(38) << std::endl;
  return 0;
}
