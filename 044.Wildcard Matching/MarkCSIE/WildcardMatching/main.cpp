#include <iostream>

class Solution
{
public:
  bool isMatch(const std::string& s, const std::string& p)
  {
    size_t s_index = 0;
    size_t ss_index = 0;
    size_t p_index = 0;
    int star_index = -1;
    while (s_index < s.length())
    {
      if (s[s_index] == p[p_index] || p[p_index] == '?')
      {
        ++s_index;
        ++p_index;
      }
      else if (p[p_index] == '*')
      {
        star_index = p_index;
        p_index++;
        ss_index = s_index;
      }
      else if (star_index != -1)
      {
        p_index = star_index + 1;
        ++ss_index;
        s_index = ss_index;
      }
      else
      {
        return false;
      }
    }
    while (p_index < p.length() && p[p_index] == '*')
    {
      ++p_index;
    }
    if (p_index != p.length())
    {
      return false;
    }
    else
    {
      return true;
    }
  }
};

int main()
{
  Solution solution;
  std::cout << solution.isMatch("aa", "a") << std::endl;
  return 0;
}
