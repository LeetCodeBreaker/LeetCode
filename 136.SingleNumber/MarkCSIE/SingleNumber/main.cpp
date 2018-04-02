#include <iostream>
#include <vector>

class Solution
{
public:
  int singleNumber(const std::vector<int>& nums)
  {
    int answer = 0;
    for (const int& i : nums)
    {
      answer ^= i;
    }
    return answer;
  }
};

int main()
{
  Solution solution;
  std::cout << solution.singleNumber({1, 1, 2, 2, 3}) << std::endl;
  return 0;
}
