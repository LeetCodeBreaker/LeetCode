#include <iostream>
#include <string>
#include <vector>

class Solution
{
public:
  bool checkInclusion(const std::string &s1, const std::string &s2)
  {
    int length1 = s1.length();
    int length2 = s2.length();

    std::vector<int> s1map(26, 0);
    std::vector<int> s2map(26, 0);
    for (size_t i = 0; i < length1; ++i)
    {
      ++s1map[s1[i] - 'a'];
      ++s2map[s2[i] - 'a'];
    }

    int matching_count = 0;
    for (size_t i = 0; i < 26; i++)
    {
      if (s1map[i] == s2map[i])
      {
        ++matching_count;
      }
    }

    for (int i = 0; i < length2 - length1; ++i)
    {
      if (matching_count == 26)
      {
        return true;
      }

      int right_letter = s2[i + length1] - 'a';
      int left_letter = s2[i] - 'a';

      ++s2map[right_letter];
      if (s2map[right_letter] == s1map[right_letter])
      {
        ++matching_count;
      }
      else if (s2map[right_letter] - 1 == s1map[right_letter])
      {
        --matching_count;
      }

      --s2map[left_letter];
      if (s2map[left_letter] == s1map[left_letter])
      {
        ++matching_count;
      }
      else if (s2map[left_letter] + 1 == s1map[left_letter])
      {
        --matching_count;
      }
    }

    return (matching_count == 26);
  }
};

int main()
{
  Solution solution;
  std::cout << solution.checkInclusion("ab", "eidbaooo") << std::endl;
  return 0;
}
