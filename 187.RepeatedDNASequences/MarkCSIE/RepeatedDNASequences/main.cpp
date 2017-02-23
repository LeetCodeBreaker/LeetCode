#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
  std::vector<std::string> findRepeatedDnaSequences(const std::string &s)
  {
    // unordered_map<int, int> map;
    int map[1024*1024] = {0};
    // use 2 bits to store a character: (s[i] >> 1) & 3
    // use 1 interger to store a 10 digit substring
    int t = 0;
    unsigned int i = 0;
    while (i < 9)
    {
      t = t | ((s[i] >> 1) & 3);
      t = t << 2;
      i++;
    }

    std::vector<std::string> answer;
    while (i < s.length())
    {
      t = t | ((s[i] >> 1) & 3);
      map[t]++;
      if (map[t] == 2)
      {
        answer.push_back(s.substr(i - 9, 10));
      }
      t = t << 2;
      t = t & 0xFFFFF;
      i++;
    }

    return answer;
  }
};

int main()
{
  Solution solution;
  for (const std::string &s : solution.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"))
  {
    std::cout << s << std::endl;
  }
  return 0;
}
