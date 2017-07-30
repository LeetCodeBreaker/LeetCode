#include <iostream>
#include <string>
#include <unordered_map>

class Solution
{
public:
  bool isAnagram(std::string s, std::string t)
  {
    if (s.length() != t.length())
    {
      return false;
    }

    std::unordered_map<char, int> char_count;
    for (const char &c : s)
    {
      ++char_count[c];
    }

    for (const char &c : t)
    {
      --char_count[c];
      if (char_count[c] < 0)
      {
        return false;
      }
    }
    return true;
  }
};

int main()
{
  Solution solution;
  std::cout << solution.isAnagram("anagram", "nagaram") << std::endl;
}
