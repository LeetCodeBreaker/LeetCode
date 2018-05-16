#include <iostream>
#include <vector>

class Solution
{
public:
  std::vector<std::vector<int>> flipAndInvertImage(std::vector<std::vector<int>>& A)
  {
    // std::vector<std::vector<int>> output_image(A);
    // for (int i = 0; i < A.size(); ++i)
    // {
    //   for (int j = 0; j < A[i].size(); ++j)
    //   {
    //     output_image[i][j] = A[i][A[i].size() - j - 1] == 0 ? 1 : 0;
    //   }
    // }
    // return output_image;

    for (size_t i = 0; i < A.size(); ++i)
    {
      int n = A[i].size();
      for (int j = 0; j < n / 2; ++j)
      {
        std::swap(A[i][j], A[i][n - j - 1]);
        A[i][j] = (A[i][j] == 1) ? 0 : 1;
        A[i][n - j - 1] = (A[i][n - j - 1] == 1) ? 0 : 1;
      }
      if (n % 2 != 0)
      {
        A[i][n/2] = (A[i][n/2] == 1) ? 0 : 1;
      }
    }
    return A;
  }
};

int main()
{
  Solution solution;
  std::vector<std::vector<int>> test = {{1, 1, 0},
                                        {1, 0, 1},
                                        {0, 0, 0}};
  for (const std::vector<int>& row : solution.flipAndInvertImage(test))
  {
    for (const int& i : row)
    {
      std::cout << i << " ";
    }
    std::cout << std::endl;
  }
  return 0;
}
