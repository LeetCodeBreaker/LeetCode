#include <iostream>
#include <vector>
#include <cctype>

class Solution
{
public:
  std::vector<std::string> letterCasePermutation(const std::string& S)
  {
    std::vector<std::string> answer(1, S);
    for (size_t i = 0; i < S.length(); ++i)
    {
      char letter = S[i];
      if (!std::isalpha(letter))
      {
        continue;
      }

      if (std::islower(letter))
      {
        letter = std::toupper(letter);
      }
      else
      {
        letter = std::tolower(letter);
      }

      size_t answer_size = answer.size();
      for (size_t j = 0; j < answer_size; ++j)
      {
        answer.push_back(answer[j]);
        answer.back()[i] = letter;
      }
    }
    return answer;
  }
};

int main()
{
  Solution solution;
  for (const std::string& s : solution.letterCasePermutation("a1b2"))
  {
    std::cout << s << std::endl;
  }
  return 0;
}
