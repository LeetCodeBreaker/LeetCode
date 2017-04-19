#include <iostream>
#include <vector>

class Solution
{
public:
  bool canFinish(const unsigned int &numCourses, const std::vector<std::pair<int, int>>& prerequisites)
  {
    std::vector<std::vector<unsigned int>> edges(numCourses);
    std::vector<bool> edges_bool(numCourses, false);
    for (const std::pair<unsigned int, unsigned int> &p : prerequisites)
    {
      edges[p.first].push_back(p.second);
      edges_bool[p.first] = true;
    }

    for (size_t i = 0; i < edges_bool.size(); i++)
    {
      if (edges_bool[i] == true)
      {
        std::vector<bool> prerequisite_vector(numCourses, false);
        if (findloop(edges[i][0], prerequisite_vector, edges, edges_bool))
        {
          return false;
        }
      }
    }
    return true;
  }

private:
  bool findloop(const unsigned int &course, std::vector<bool> &prerequisite_vector, std::vector<std::vector<unsigned int>> &edges, std::vector<bool> &edges_bool)
  {
    if (prerequisite_vector[course] == true)
    {
      return true;
    }
    prerequisite_vector[course] = true;

    while (edges[course].size() > 0)
    {
      unsigned int head_course = edges[course].back();
      edges[course].pop_back();
      std::vector<bool> temp_prerequisite_vector = prerequisite_vector;
      if (findloop(head_course, temp_prerequisite_vector, edges, edges_bool))
      {
        return true;
      }
    }
    edges_bool[course] = false;
    return false;
  }
};

int main()
{
  Solution solution;
  std::cout << solution.canFinish(2, {{1, 0}}) << std::endl;
  return 0;
}
