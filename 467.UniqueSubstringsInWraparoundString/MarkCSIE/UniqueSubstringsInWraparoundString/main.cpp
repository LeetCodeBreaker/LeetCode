#include <iostream>
#include <vector>

class Solution
{
public:
  unsigned int findSubstringInWraproundString(const std::string &p)
  {
    std::vector<unsigned int> table(26, 0);

    unsigned int count = 1;
    for (unsigned int i = 0; i < p.length(); i++)
    {
      if (i > 0 && (p[i] - p[i-1] == 1 || (p[i] == 'a' && p[i-1] == 'z')))
      {
        count++;
      }
      else
      {
        count = 1;
      }

      if (count > table[p[i] - 'a'])
      {
        table[p[i] - 'a'] = count;
      }
    }

    unsigned int answer = 0;
    for (const unsigned int &i : table)
    {
      answer += i;
    }
    return answer;
  }
};

int main()
{
  Solution solution;
  std::cout << solution.findSubstringInWraproundString("zab") << std::endl;
  return 0;
}
