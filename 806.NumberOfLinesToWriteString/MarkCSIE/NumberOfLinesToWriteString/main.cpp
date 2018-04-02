#include <iostream>
#include <vector>

class Solution
{
public:
  std::vector<int> numberOfLines(const std::vector<int>& widths, const std::string& S)
  {
    int width = 0;
    int lines = 1;
    for (const char& c : S)
    {
      width += widths[c - 'a'];
      if (width > 100)
      {
        ++lines;
        width = widths[c - 'a'];
      }
    }
    return std::vector<int>({lines, width});
  }
};

int main()
{
  Solution solution;
  std::vector<int> answer = solution.numberOfLines({4,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10}, "bbbcccdddaaa");
  std::cout << answer[0] << std::endl;
  std::cout << answer[1] << std::endl;
  return 0;
}
