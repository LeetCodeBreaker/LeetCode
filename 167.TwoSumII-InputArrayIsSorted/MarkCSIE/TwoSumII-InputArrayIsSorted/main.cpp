#include <iostream>
#include <vector>

class Solution
{
public:
  std::vector<int> twoSum(const std::vector<int> &numbers, const int &target)
  {
    size_t front = 0;
    size_t back = numbers.size() - 1;
    std::vector<int> answer(2, 0);
    while (true)
    {
      int sum = numbers[front] + numbers[back];
      if (sum == target)
      {
        answer[0] = front + 1;
        answer[1] = back + 1;
        return answer;
      }
      else if (sum < target)
      {
        front++;
      }
      else
      {
        back--;
      }
    }
    return answer;
  }
};

int main()
{
  Solution solution;
  for (const int &i : solution.twoSum({2, 7, 11, 15}, 9))
  {
    std::cout << i << std::endl;
  }
  return 0;
}
