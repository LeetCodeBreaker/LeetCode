#include <iostream>
#include <vector>
#include <unordered_map>

class Solution
{
public:
  int subarraySum(const std::vector<int> &nums, const int &k)
  {
    int answer = 0;
    std::unordered_map<int, int> sum_map;
    sum_map[0]++; // to take into account those subarrays that begin with index 0
    int sum = 0;
    for (const int &i : nums)
    {
      sum += i;
      answer += sum_map[sum-k];
      sum_map[sum]++;
    }
    return answer;
  }
};

int main()
{
  Solution solution;
  std::cout << solution.subarraySum({1, 1, 1}, 2) << std::endl;
  return 0;
}
