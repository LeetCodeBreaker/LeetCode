#include <iostream>
#include <string>
#include <cmath>

class Solution 
{
public:
  int titleToNumber(const std::string& s) 
  {
    int answer = 0;
    for (const char& c : s)
    {
      answer = answer * 26 + c - 'A' + 1;
    }
    return answer;
  }
};

int main() {
  Solution solution;
  std::cout << solution.titleToNumber("AB") << std::endl;
  return 0;
}

