#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
  int minMoves2(std::vector<int> nums)
  {
    // The algorithm used is typically introselect (variant of quickselect)
    // Worst-case: O(n) Average-case: O(n)
    std::nth_element(nums.begin(), nums.begin() + nums.size() / 2, nums.end());

    int median = nums[nums.size() / 2];
    int answer = 0;
    for (const int &i : nums)
    {
      answer += std::abs(i - median);
    }
    return answer;
  }
};

int main()
{
  Solution solution;
  std::cout << solution.minMoves2({1, 2, 3}) << std::endl;
  return 0;
}
