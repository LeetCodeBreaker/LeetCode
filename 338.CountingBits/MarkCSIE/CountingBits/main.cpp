#include <iostream>
#include <vector>

class Solution
{
public:
  std::vector<int> countBits(const unsigned int &num)
  {
    std::vector<int> answer(num + 1, 0);
    for (unsigned int i = 1; i <= num; i++)
    {
      answer[i] = answer[i & (i-1)] + 1;
    }
    return answer;
  }
};

int main()
{
  Solution solution;
  for (const unsigned int &i : solution.countBits(5))
  {
    std::cout << i << std::endl;
  }
  return 0;
}
