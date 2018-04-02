#include <iostream>

class Solution
{
public:
  bool rotateString(const std::string& A, const std::string& B)
  {
    if (A.length() != B.length())
    {
      return false;
    }
    std::string AA = A + A;
    if (AA.find(B) != std::string::npos)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
};

int main()
{
  Solution solution;
  std::cout << solution.rotateString("abcde", "cdeab") << std::endl;
  return 0;
}
