#include <iostream>
#include <string>

class Solution {
public:
  std::string toHex(int num)
  {
    if (num == 0)
    {
      return "0";
    }

    std::string answer;
    unsigned int unsigned_num = num;
    while (unsigned_num > 0)
    {
      unsigned int num = unsigned_num % 16;
      switch(num)
      {
        case 15:
          answer = "f" + answer;
          break;
        case 14:
          answer = "e" + answer;
          break;
        case 13:
          answer = "d" + answer;
          break;
        case 12:
          answer = "c" + answer;
          break;
        case 11:
          answer = "b" + answer;
          break;
        case 10:
          answer = "a" + answer;
          break;
        default:
          answer = std::to_string(num) + answer;
      }

      unsigned_num /= 16;
    }
    return answer;
  }
};

int main()
{
  Solution solution;
  std::cout << solution.toHex(26) << std::endl;
}
