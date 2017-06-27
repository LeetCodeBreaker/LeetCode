#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
#include <cmath>

class Solution
{
public:
  int numberOfBoomerangs(const std::vector<std::pair<int, int>> &points)
  {
    int answer = 0;
    for (const std::pair<int, int> &p1 : points)
    {
      std::unordered_map<unsigned int, size_t> length_map;
      for (const std::pair<int, int> &p2 : points)
      {
        unsigned int length = std::pow(p1.first - p2.first, 2) + std::pow(p1.second - p2.second, 2);
        if (length_map[length] != 0)
        {
          answer += (length_map[length] * 2);
        }
        length_map[length]++;
      }
    }
    return answer;
  }
};

int main()
{
  Solution solution;
  std::cout << solution.numberOfBoomerangs({{0, 0}, {1, 0}, {2, 0}}) << std::endl;
  return 0;
}
