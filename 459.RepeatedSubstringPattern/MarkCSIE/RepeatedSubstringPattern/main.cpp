#include <iostream>
#include <string>

class Solution
{
public:
  bool repeatedSubstringPattern(const std::string &s)
  {
    for (unsigned int i = s.length() / 2; i >= 1; --i)
    {
      if (s.length() % i == 0)
      {
        std::string sub_string = s.substr(0, i);
        bool pass = true;
        for (unsigned int j = 1; j < s.length() / i; ++j)
        {
          if (s.compare(j * i, i, sub_string) != 0)
          {
            pass = false;
            break;
          }
        }
        if (pass == true)
        {
          return true;
        }
      }
    }
    return false;
  }
};

int main()
{
  Solution solution;
  std::cout << solution.repeatedSubstringPattern("abab") << std::endl;
  return 0;
}
