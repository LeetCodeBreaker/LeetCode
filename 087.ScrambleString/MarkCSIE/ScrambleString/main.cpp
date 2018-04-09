#include <iostream>
#include <unordered_map>

class Solution
{
public:
  bool isScramble(const std::string& s1, const std::string& s2)
  {
    if (s1 == s2)
    {
      return true;
    }

    std::vector<int> char_map(256, 0);
    for (const char& c : s1)
    {
      ++char_map[c];
    }
    for (const char& c : s2)
    {
      --char_map[c];
      if (char_map[c] < 0)
      {
        return false;
      }
    }

    size_t length = s1.length();
    for (size_t i = 0; i < length - 1; ++i)
    {
      std::string left1 = s1.substr(0, i+1);
      std::string right1 = s1.substr(i+1);

      std::string left2 = s2.substr(0, i+1);
      std::string right2 = s2.substr(i+1);
      std::string left2_2 = s2.substr(0, length - i - 1);
      std::string right2_2 = s2.substr(length - i - 1);

      if ((isScramble(left1, left2) && isScramble(right1, right2)) ||
          (isScramble(left1, right2_2) && isScramble(right1, left2_2)))
      {
        return true;
      }
    }
    return false;
  }
};

int main()
{
  Solution solution;
  std::cout << solution.isScramble("great", "rgtae") << std::endl;

  return 0;
}
