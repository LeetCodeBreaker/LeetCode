#include <iostream>

class Solution
{
public:
  bool isNumber(std::string s)
  {
    while (s.front() == ' ')
    {
      s.erase(0, 1);
    }
    while (s.back() == ' ')
    {
      s.pop_back();
    }

    bool pointSeen = false;
    bool eSeen = false;
    bool numberSeen = false;
    bool numberAfterE = true;
    for (size_t i = 0; i < s.length(); ++i)
    {
      if ('0' <= s[i] && s[i] <= '9')
      {
        numberSeen = true;
        numberAfterE = true;
      }
      else if (s[i] == '.')
      {
        if (eSeen || pointSeen)
        {
          return false;
        }
        pointSeen = true;
      }
      else if (s[i] == 'e')
      {
        if (eSeen || !numberSeen)
        {
          return false;
        }
        numberAfterE = false;
        eSeen = true;
      }
      else if (s[i] == '-' || s[i] == '+')
      {
        if (i != 0 && s[i-1] != 'e')
        {
          return false;
        }
      }
      else
      {
        return false;
      }
    }

    return numberSeen && numberAfterE;
  }
};

int main()
{
  Solution solution;
  std::cout << solution.isNumber(" 0.1 ") << std::endl;

  return 0;
}
