#include <iostream>
#include <string>

class Solution
{
public:
  std::string reverseString(std::string s)
  {
    for (size_t i = 0; i < s.length() / 2; ++i)
    {
      std::swap(s[i], s[s.length()-1-i]);
    }
    return s;
  }
};

int main()
{
  Solution solution;
  std::cout << solution.reverseString("hello") << std::endl;
}
