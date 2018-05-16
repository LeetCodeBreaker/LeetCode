#include <iostream>
#include <vector>

class Solution
{
public:
  void merge(std::vector<int>& nums1, int m, const std::vector<int>& nums2, int n)
  {
    for (int i = m + n - 1; i >= 0; --i)
    {
      if (m-1 < 0 || (n-1 >= 0 && nums2[n-1] > nums1[m-1]))
      {
        nums1[i] = nums2[n-1];
        --n;
      }
      else
      {
        nums1[i] = nums1[m-1];
        --m;
      }
    }
  }
};

int main()
{
  Solution solution;
  std::vector<int> test = {1, 2, 3, 0, 0, 0};
  solution.merge(test, 3, {2, 5, 6}, 3);
  for (const int& i : test)
  {
    std::cout << i << std::endl;
  }
  return 0;
}
