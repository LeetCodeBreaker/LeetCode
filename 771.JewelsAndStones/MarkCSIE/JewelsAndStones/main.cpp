#include <iostream>
#include <unordered_set>

class Solution
{
public:
  int numJewelsInStones(const std::string& J, const std::string& S)
  {
    std::unordered_set<char> jewel_set(J.begin(), J.end());

    int answer = 0;
    for (const char& c : S)
    {
      if (jewel_set.count(c))
      {
        ++answer;
      }
    }
    return answer;
  }
};

int main()
{
  Solution solution;
  std::cout << solution.numJewelsInStones("aA", "aAAbbbb") << std::endl;
  return 0;
}
