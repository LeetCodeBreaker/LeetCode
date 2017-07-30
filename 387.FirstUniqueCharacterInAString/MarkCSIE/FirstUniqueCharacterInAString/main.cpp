#include <iostream>
#include <unordered_map>

class Solution
{
public:
  int firstUniqChar(const std::string &s)
  {
    std::unordered_map<char, size_t> unique_map;
    for (size_t i = 0; i < s.size(); ++i)
    {
      if (unique_map.find(s[i]) == unique_map.end())
      {
        unique_map[s[i]] = i;
      }
      else
      {
        unique_map[s[i]] = s.length();
      }
    }

    size_t answer = s.length();
    for (const auto &p : unique_map)
    {
      answer = std::min(answer, p.second);
    }

    if (answer == s.length())
    {
      return -1;
    }
    else
    {
      return answer;
    }
  }
};

int main()
{
  Solution solution;
  std::cout << solution.firstUniqChar("leetcode") << std::endl;
  return 0;
}
