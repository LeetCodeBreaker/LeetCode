#include <iostream>
#include <vector>
#include <unordered_set>

class Solution
{
public:
  std::vector<std::string> findWords(const std::vector<std::string>& words)
  {
    std::vector<std::unordered_set<char>> rows = {{'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'},
                                                  {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'},
                                                  {'z', 'x', 'c', 'v', 'b', 'n', 'm'}};
    std::vector<std::string> answer;
    for (const std::string& s : words)
    {
      int prev_row = -1;
      bool same_row = true;
      for (size_t i = 0; i < s.length(); ++i)
      {
        char letter = tolower(s[i]);
        int row = 0;
        for (size_t j = 0; j < rows.size(); ++j)
        {
          if (rows[j].find(letter) != rows[j].end())
          {
            row = j;
            break;
          }
        }
        if (prev_row != -1 && row != prev_row)
        {
          same_row = false;
          break;
        }
        prev_row = row;
      }
      if (same_row)
      {
        answer.emplace_back(s);
      }
    }
    return answer;
  }
};

int main()
{
  Solution solution;
  for (const std::string& s: solution.findWords({"Hello", "Alaska", "Dad", "Peace"}))
  {
    std::cout << s << std::endl;
  }

  return 0;
}
