#include <iostream>
#include <vector>

class Solution
{
public:
  unsigned int findCircleNum(const std::vector<std::vector<int>> &M)
  {
    std::vector<bool> traversed(M.size(), false);
    unsigned int answer = 0;
    for (size_t i = 0; i < M.size(); i++)
    {
      if (!traversed[i])
      {
        dfs(i, M, traversed);
        ++answer;
      }
    }
    return answer;
  }

protected:
  void dfs(const size_t &index, const std::vector<std::vector<int>> &M, std::vector<bool> &traversed)
  {
    traversed[index] = true;
    for (size_t i = 0; i < M[index].size(); i++)
    {
      if (M[index][i] == 1 && !traversed[i])
      {
        dfs(i, M, traversed);
      }
    }
  }
};

int main()
{
  Solution solution;
  std::cout << solution.findCircleNum({{1, 1, 0}, {1, 1, 0}, {0, 0, 1}}) << std::endl;
  return 0;
}
