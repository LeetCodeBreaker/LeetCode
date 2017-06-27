#include <iostream>

class Solution
{
protected:
  std::string stringPlus(const std::string& str1, const std::string& str2)
  {
    std::string answer = "";
    int index1 = str1.length() - 1;
    int index2 = str2.length() - 1;

    bool carry = false;
    while (index1 >= 0 || index2 >= 0)
    {
      int num1 = 0;
      if (index1 >= 0)
      {
        num1 = str1[index1] - '0';
      }
      int num2 = 0;
      if (index2 >= 0)
      {
        num2 = str2[index2] - '0';
      }

      int sum = num1 + num2 + carry;
      answer = std::to_string(sum % 10) + answer;
      carry = (sum > 9);

      --index1;
      --index2;
    }
    if (carry)
    {
      answer = '1' + answer;
    }

    return answer;
  }

  bool recursive(const std::string& str1, const std::string& str2, const std::string& num)
  {
    std::string sum = stringPlus(str1, str2);
    if (sum == num.substr(0, sum.length()))
    {
      std::string rest = num.substr(sum.length());
      if (rest.length() == 0)
      {
        return true;
      }
      else
      {
        return recursive(str2, sum, rest);
      }
    }
    return false;
  }
public:
  bool isAdditiveNumber(const std::string& num)
  {
    for (size_t len1 = 1; len1 <= num.length() / 2; ++len1)
    {
      std::string str1 = num.substr(0, len1);
      if (str1[0] == '0' && str1.length() > 1)
      {
        break;
      }
      for (size_t len2 = 1; len2 <= (num.length() - len1) / 2; ++len2)
      {
        std::string str2 = num.substr(len1, len2);
        if (str2[0] == '0' && str2.length() > 1)
        {
          break;
        }
        if (recursive(str1, str2, num.substr(len1 + len2)))
        {
          return true;
        }
      }
    }
    return false;
  }
};

int main()
{
  Solution solution;
  std::cout << solution.isAdditiveNumber("112358") << std::endl;
  return 0;
}
