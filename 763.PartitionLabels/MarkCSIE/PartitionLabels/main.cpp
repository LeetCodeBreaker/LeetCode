#include <iostream>
#include <vector>

class Solution
{
public:
  std::vector<int> partitionLabels(const std::string& S)
  {
    std::vector<int> right_most_index(26, 0);
    for (size_t i = 0; i < S.length(); ++i)
    {
      right_most_index[S[i] - 'a'] = i;
    }

    std::vector<int> answer;
    int begin = 0;
    int right_most = 0;
    for (size_t i = 0; i < S.length(); ++i)
    {
      right_most = std::max(right_most, right_most_index[S[i] - 'a']);
      if (right_most == i)
      {
        answer.emplace_back(i - begin + 1);
        begin = i + 1;
      }
    }
    return answer;
  }
};

int main()
{
  Solution solution;
  for (const int& i : solution.partitionLabels("ababcbacadefegdehijhklij"))
  {
    std::cout << i << std::endl;
  }
  return 0;
}
