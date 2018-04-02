#include <iostream>
#include <string>

class Solution
{
public:
  bool isMatch(const std::string& s, const std::string& p)
  {
    if (p.empty())
    {
      return (s.empty());
    }
    bool first_match = !s.empty() && (s[0] == p[0] || p[0] == '.');

    if (p.length() >= 2 && p[1] == '*')
    {
      return isMatch(s, p.substr(2)) || (first_match && isMatch(s.substr(1), p));
    }
    else
    {
      return first_match && isMatch(s.substr(1), p.substr(1));
    }
  }
};

int main()
{
  Solution solution;
  std::cout << solution.isMatch("aab", "c*a*b") << std::endl;
  return 0;
}
