#include <iostream>
#include <vector>
#include <unordered_map>

class Solution
{
public:
  unsigned int fourSumCount(const std::vector<int> &A, const std::vector<int> &B, const std::vector<int> &C, const std::vector<int> &D)
  {
    std::unordered_map<int, unsigned int> sum_map;
    for (size_t i = 0; i < A.size(); ++i)
    {
      for (size_t j = 0; j < B.size(); ++j)
      {
        sum_map[-(A[i] + B[j])]++;
      }
    }

    unsigned int answer = 0;
    for (size_t i = 0; i < C.size(); ++i)
    {
      for (size_t j = 0; j < D.size(); ++j)
      {
        answer += sum_map[C[i] + D[j]];
      }
    }
    return answer;
  }
};

int main()
{
  Solution solution;
  std::cout << solution.fourSumCount({1, 2}, {-2, -1}, {-1, 2}, {0, 2}) << std::endl;
  return 0;
}
