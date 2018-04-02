#include <iostream>
#include <vector>

class Solution
{
public:
  int longestValidParentheses(std::string s)
  {
    if (s.length() == 0)
    {
      return 0;
    }

    // DP: O(n) time, O(n) space
    // int answer = 0;
    // std::vector<int> dp(s.length(), 0);
    // for (int i = 1; i < s.length(); ++i)
    // {
    //   if (s[i] == ')')
    //   {
    //     if (s[i-1] == '(')
    //     {
    //       if (i == 1)
    //       {
    //         dp[i] = 2;
    //       }
    //       else
    //       {
    //         dp[i] = dp[i-2] + 2;
    //       }
    //     }
    //     else
    //     {
    //       if (s[i - dp[i-1] - 1] == '(')
    //       {
    //         dp[i] = dp[i - dp[i-1] - 2] + dp[i-1] + 2;
    //       }
    //     }
    //   }
    //   answer = std::max(answer, dp[i]);
    // }
    // return answer;

    // Two traversals: O(2n) time, O(1) space
    int left = 0;
    int right = 0;
    int answer = 0;
    for (const char& c : s)
    {
      if (c == '(')
      {
        ++left;
      }
      else
      {
        ++right;
      }
      if (left == right)
      {
        answer = std::max(answer, 2 * left);
      }
      else if (right > left)
      {
        left = 0;
        right = 0;
      }
    }

    left = 0;
    right = 0;
    for (std::string::const_reverse_iterator rit = s.rbegin(); rit != s.rend(); ++rit)
    {
      if (*rit == '(')
      {
        ++left;
      }
      else
      {
        ++right;
      }
      if (left == right)
      {
        answer = std::max(answer, 2 * left);
      }
      else if (left > right)
      {
        left = 0;
        right = 0;
      }
    }
    return answer;
  }
};

int main()
{
  Solution solution;
  std::cout << solution.longestValidParentheses(")()())") << std::endl;
  return 0;
}
