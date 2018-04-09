#include <iostream>
#include <vector>

class Solution
{
public:
  int minDistance(const std::string& word1, const std::string& word2)
  {
    // Recursive: TLE
    // int length1 = word1.length();
    // int length2 = word2.length();
    // if (length1 == 0)
    // {
    //   return length2;
    // }
    // if (length2 == 0)
    // {
    //   return length1;
    // }
    // int min = std::max(length1, length2);
    // min = std::min(min, 1 + minDistance(word1.substr(1), word2));
    // min = std::min(min, 1 + minDistance(word1, word2.substr(1)));
    // if (word1.front() != word2.front())
    // {
    //   min = std::min(min, 1 + minDistance(word1.substr(1), word2.substr(1)));
    // }
    // else
    // {
    //   min = std::min(min, minDistance(word1.substr(1), word2.substr(1)));
    // }

    // DP:
    size_t length1 = word1.length();
    size_t length2 = word2.length();
    std::vector<int> dp(length2 + 1, 0);
    for (int j = 1; j <= length2; j++)
    {
      dp[j] = j;
    }
    for (size_t i = 1; i <= length1; ++i)
    {
      int left_top = dp[0];
      dp[0] = i;
      for (size_t j = 1; j <= length2; ++j)
      {
        int temp = dp[j];
        if (word1[i - 1] == word2[j - 1])
        {
          dp[j] = left_top;
        }
        else
        {
          dp[j] = std::min(left_top + 1, std::min(dp[j-1] + 1, dp[j] + 1));
        }
        left_top = temp;
      }
    }
    return dp[length2];
  }
};

int main()
{
  Solution solution;
  std::cout << solution.minDistance("dinitrophenylhydrazine", "acetylphenylhydrazine") << std::endl;

  return 0;
}
