#include <iostream>
#include <vector>
#include <limits>

class Solution
{
public:
std::string minWindow(const std::string& s, const std::string& t)
  {
    std::vector<int> map(128, 0);
    for (const char& c: t)
    {
      map[c]++;
    }
    int counter = t.length();
    int begin = 0;
    int end = 0;
    int d = std::numeric_limits<int>::max();
    int head = 0;
    while (end < s.length())
    {
      if (map[s[end]] > 0)
      {
        --counter;
      }
      --map[s[end]];
      ++end;
      while (counter == 0)
      {
        if (end - begin < d)
        {
          d = end - begin;
          head = begin;
        }
        if (map[s[begin]] == 0)
        {
          ++counter;
        }
        ++map[s[begin]];
        ++begin;
      }
    }
    if (d == std::numeric_limits<int>::max())
    {
      return "";
    }
    else
    {
      return s.substr(head, d);
    }
  }
};

int main()
{
  Solution solution;
  std::cout << solution.minWindow("ADOBECODEBANC", "ABC") << std::endl;

  return 0;
}
