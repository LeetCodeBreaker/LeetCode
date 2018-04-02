#include <iostream>
#include <vector>

class Solution
{
public:
  int trap(const std::vector<int>& height)
  {
    if (height.size() == 0)
    {
      return 0;
    }

    int left_max = height.front();
    int right_max = height.back();
    int left = 0;
    int right = height.size() - 1;
    int answer = 0;
    while (left < right)
    {
      if (left_max <= right_max)
      {
        ++left;
        left_max = std::max(left_max, height[left]);
        if (height[left] < left_max)
        {
          answer += left_max - height[left];
        }
      }
      else
      {
        --right;
        right_max = std::max(right_max, height[right]);
        if (height[right] < right_max)
        {
          answer += right_max - height[right];
        }
      }
    }
    return answer;

  }
};
int main()
{
  Solution solution;
  std::cout << solution.trap({0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}) << std::endl;
  return 0;
}
