#include <iostream>
#include <vector>

class Solution
{
public:
  bool isInterleave(const std::string& s1, const std::string& s2, const std::string& s3)
  {
    std::vector<std::vector<int>> memo(s1.length(), std::vector<int>(s2.length(), -1));
    return recursive(s1, s2, s3, 0, 0, 0, memo);
  }

protected:
  bool recursive(const std::string& s1, const std::string& s2, const std::string& s3,
                 const size_t& i, const size_t& j, const size_t& k,
                 std::vector<std::vector<int>>& memo)
  {
    if (i == s1.length())
    {
      return s2.substr(j) == s3.substr(k);
    }
    else if (j == s2.length())
    {
      return s1.substr(i) == s3.substr(k);
    }

    if (memo[i][j] != -1)
    {
      return memo[i][j];
    }

    bool answer = false;
    if ((s3[k] == s1[i] && recursive(s1, s2, s3, i + 1, j, k + 1, memo)) ||
        (s3[k] == s2[j] && recursive(s1, s2, s3, i, j + 1, k + 1, memo)))
    {
      answer = true;
    }
    memo[i][j] = answer;
    return answer;
  }
};

int main()
{
  Solution solution;
  std::cout << solution.isInterleave("aabcc", "dbbca", "aadbbcbcac") << std::endl;
  return 0;
}

