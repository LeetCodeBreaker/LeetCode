#include <iostream>
#include <vector>
#include <unordered_set>

class Solution
{
public:
  int uniqueMorseRepresentations(const std::vector<std::string>& words)
  {
    std::vector<std::string> morse_code({".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."});

    std::unordered_set<std::string> transformations;

    for (const std::string& s : words)
    {
      std::string transformation = "";
      for (const char& c : s)
      {
        transformation += morse_code[c - 'a'];
      }
      transformations.insert(transformation);
    }
    return transformations.size();
  }
};

int main()
{
  Solution solution;
  std::cout << solution.uniqueMorseRepresentations({"gin", "zen", "gig", "msg"}) << std::endl;
  return 0;
}
