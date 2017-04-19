#include <iostream>
#include <vector>

class Solution
{
public:
  int findPoisonedDuration(const std::vector<int>& timeSeries, const unsigned int &duration)
  {
    if (timeSeries.size() == 0)
    {
        return 0;
    }
    int answer = 0;
    for (int i = 0; i < timeSeries.size() - 1; i++)
    {
      if (timeSeries[i] + duration <= timeSeries[i+1])
      {
        answer += duration;
      }
      else
      {
        answer += timeSeries[i+1] - timeSeries[i];
      }
    }

    answer += duration;
    return answer;
  }
};

int main()
{
  Solution solution;
  std::cout << solution.findPoisonedDuration({1, 4}, 2) << std::endl;
  return 0;
}
