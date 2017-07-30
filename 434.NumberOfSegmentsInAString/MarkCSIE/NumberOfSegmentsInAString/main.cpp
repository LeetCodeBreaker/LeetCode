#include <iostream>

class Solution
{
public:
  unsigned int countSegments(const std::string &s)
  {
    unsigned int count = 0;
    size_t i = 0;
    while (i < s.length())
    {
      if (s[i] != ' ')
      {
        count++;
        while (i < s.length() && s[i] != ' ')
        {
          i++;
        }
      }
      i++;
    }
    return count;
  }
};

int main()
{
  Solution solution;
  std::cout << solution.countSegments("Hello, my name is John") << std::endl;
  return 0;
}
