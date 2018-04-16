#include <iostream>
#include <stack>

class Solution
{
public:
  bool isValid(const std::string& s)
  {
    std::stack<char> parenthesis_stack;
    for (const char& c : s)
    {
      if (c == '(' || c == '[' || c == '{')
      {
        parenthesis_stack.push(c);
      }
      else
      {
        if (c == ')')
        {
          if (parenthesis_stack.empty() || parenthesis_stack.top() != '(')
          {
            return false;
          }
        }
        else if (c == ']')
        {
          if (parenthesis_stack.empty() || parenthesis_stack.top() != '[')
          {
            return false;
          }
        }
        else if (c == '}')
        {
          if (parenthesis_stack.empty() || parenthesis_stack.top() != '{')
          {
            return false;
          }
        }
        parenthesis_stack.pop();
      }
    }
    return parenthesis_stack.empty() ? true : false;
  }
};

int main()
{
  Solution solution;
  std::cout << solution.isValid("()[]{}") << std::endl;
  return 0;
}
