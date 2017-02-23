#include <iostream>
#include <vector>

class Solution {
private:
  int base = 1337;

  // (a^k) % base
  int powMod(int a, int k)
  {
    if (k == 0)
    {
      return 1;
    }

    a %= base;
    int result = a;
    for (unsigned i = 0; i < k - 1; i++)
    {
      result = (result * a) % base;
    }
    return result;
  }

public:
  int superPow(int a, std::vector<int> &b) {
    if (b.size() == 0)
    {
      return 1;
    }

    int last_digit = b.back();
    b.pop_back();

    return (powMod(superPow(a, b), 10) * powMod(a, last_digit)) % base;
  }
};

int main()
{
  Solution solution;
  std::vector<int> b = {1, 0};
  std::cout << solution.superPow(2, b) << std::endl;
  return 0;
}
