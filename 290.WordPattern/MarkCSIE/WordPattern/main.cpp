#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <unordered_set>

class Solution
{
public:
  bool wordPattern(const std::string &pattern, const std::string &str)
  {
    std::unordered_map<char, std::string> pattern_map;
    std::unordered_set<std::string> word_set;

    unsigned int i = 0;
    std::istringstream input(str);
    for (std::string word; input >> word; i++)
    {
      if (pattern_map.find(pattern[i]) == pattern_map.end() && word_set.find(word) == word_set.end())
      {
        pattern_map[pattern[i]] = word;
        word_set.insert(word);
      }
      else if (word != pattern_map[pattern[i]])
      {
        return false;
      }
    }
    return (i == pattern.length());
  }
};

int main()
{
  Solution solution;
  std::cout << solution.wordPattern("abba", "dog cat cat dog") <<std::endl;
  return 0;
}
