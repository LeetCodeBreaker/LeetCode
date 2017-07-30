#include <iostream>
#include <vector>

class Solution
{
public:
  std::vector<int> lexicalOrder(int n)
  {
    std::vector<int> answer(n, 0);
    int curr_num = 1;
    for (size_t i = 0; i < answer.size(); i++)
    {
      answer[i] = curr_num;
      if (curr_num * 10 <= n)
      {
        curr_num *= 10;
      }
      else
      {
        if (curr_num >= n)
        {
          curr_num /= 10;
        }
        curr_num++;
        while (curr_num % 10 == 0)
        {
          curr_num /= 10;
        }
      }
    }

    return answer;
  }
};

int main()
{
  Solution solution;
  for (const int &i : solution.lexicalOrder(13))
  {
    std::cout << i << " ";
  }
  std::cout << std::endl;
  return 0;
}
