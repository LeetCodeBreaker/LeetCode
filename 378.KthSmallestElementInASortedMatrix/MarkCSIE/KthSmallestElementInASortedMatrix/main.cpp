#include <iostream>
#include <vector>
#include <queue>

class Tuple
{
public:
  Tuple(int val, std::pair<unsigned int, unsigned int> index) : val_(val), index_(index) {}

  int getValue() const
  {
    return val_;
  }

  std::pair<unsigned int, unsigned int> getIndex() const
  {
    return index_;
  }

private:
  int val_;
  std::pair<unsigned int, unsigned int> index_;
};

class Solution
{
public:
  int kthSmallest(const std::vector<std::vector<int>>& matrix, const unsigned int &k)
  {
    auto comp = [] (Tuple &a, Tuple &b) -> bool { return a.getValue() > b.getValue(); };
    std::priority_queue<Tuple, std::vector<Tuple>, decltype(comp)> min_heap(comp);

    for (unsigned int j = 0; j < matrix[0].size(); j++)
    {
      min_heap.push(Tuple(matrix[0][j], std::make_pair(0, j)));
    }

    for (unsigned int i = 0; i < k - 1; i++)
    {
      std::pair<unsigned int, unsigned int> index = min_heap.top().getIndex();
      min_heap.pop();

      if (index.first < matrix.size() - 1)
      {
        index.first++;
        min_heap.push(Tuple(matrix[index.first][index.second], index));
      }
    }

    return min_heap.top().getValue();
  }
};

int main()
{
  std::vector<std::vector<int>> matrix = {{1, 5, 9}, {10, 11, 13}, {12, 13, 15}};
  Solution solution;
  std::cout << solution.kthSmallest(matrix, 8) << std::endl;
  return 0;
}
