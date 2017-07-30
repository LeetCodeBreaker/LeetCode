#include <iostream>
#include <string>

class Solution
{
public:
  std::vector<std::string> fizzBuzz(const size_t &n)
  {
    std::vector<std::string> answer(n);
    for (size_t i = 0; i < n; i++)
    {
      if ((i+1) % 15 == 0)
      {
        answer[i] = "FizzBuzz";
      }
      else if ((i+1) % 3 == 0)
      {
        answer[i] = "Fizz";
      }
      else if ((i+1) % 5 == 0)
      {
        answer[i] = "Buzz";
      }
      else
      {
        answer[i] = std::to_string(i+1);
      }
    }
    return answer;
  }
};

int main()
{
  Solution solution;
  std::cout << solution.fizzBuzz(15) << std::endl;
  return 0;
}
