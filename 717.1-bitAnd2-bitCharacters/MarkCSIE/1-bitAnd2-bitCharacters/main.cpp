#include <iostream>
#include <vector>

class Solution
{
public:
  bool isOneBitCharacter(const std::vector<int>& bits)
  {
    bool answer = false;
    for (size_t i = 0; i < bits.size(); ++i)
    {
      if (bits[i] == 1)
      {
        ++i;
        answer = false;
      }
      else
      {
        answer = true;
      }
    }
    return answer;
  }
};

int main()
{
  Solution solution;
  std::cout << solution.isOneBitCharacter({1, 0, 0}) << std::endl;
  return 0;
}
