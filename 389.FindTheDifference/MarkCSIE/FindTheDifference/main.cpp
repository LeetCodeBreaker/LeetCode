#include <iostream>
#include <string>

class Solution
{
public:
  char findTheDifference(const std::string &s, const std::string &t)
  {
    // std::unordered_map<char, int> count_map;
    // for (const char &c : t)
    // {
    //     count_map[c]++;
    // }

    // for (const char &c : s)
    // {
    //     count_map[c]--;
    // }

    // for (const std::pair<char, int> &p : count_map)
    // {
    //     if (p.second == 1)
    //     {
    //         return p.first;
    //     }
    // }

    // XOR solution
    char r = 0;
    for (const char &c : s)
    {
      r ^=c;
    }
    for (const char &c : t)
    {
      r ^=c;
    }
    return r;
  }
};

int main()
{
  Solution solution;
  std::cout << solution.findTheDifference("abcd", "abcde") << std::endl;
  return 0;
}
