#include <iostream>

class Solution
{
public:
  bool checkRecord(const std::string &s)
  {
    unsigned int absent_count = 0;
    unsigned int ll = 0;
    for (const char &c : s)
    {
      if (c == 'A')
      {
        if (absent_count > 0)
        {
          return false;
        }
        absent_count++;
        ll = 0;
      }
      else if (c == 'L')
      {
        if (ll == 2)
        {
          return false;
        }
        ll++;
      }
      else
      {
        ll = 0;
      }
    }
    return true;
  }
};

int main()
{
  Solution solution;
  std::cout << solution.checkRecord("PPALLP") << std::endl;
  return 0;
}
