#include <iostream>
#include <vector>

class Solution
{
public:
  double findMedianSortedArrays(const std::vector<int>& nums1,
                                const std::vector<int>& nums2)
  {
    int m = nums1.size();
    int n = nums2.size();
    if (m > n)
    {
      return findMedianSortedArrays(nums2, nums1);
    }

    bool odd = ((m+n) % 2) == 1;
    int min_i = 0;
    int max_i = m;
    while (true)
    {
      int i = (min_i + max_i) / 2;
      int j = (m + n + 1) / 2 - i;
      if (i < m && nums1[i] < nums2[j-1])
      {
        min_i = i+1;
      }
      else if (i > 0 && nums1[i-1] > nums2[j])
      {
        max_i = i-1;
      }
      else
      {
        int left_max = 0;
        if (i == 0)
        {
          left_max = nums2[j-1];
        }
        else if (j == 0)
        {
          left_max = nums1[i-1];
        }
        else
        {
          left_max = std::max(nums1[i-1], nums2[j-1]);
        }
        if (odd)
        {
          return left_max;
        }
        else
        {
          int right_min = 0;
          if (i == m)
          {
            right_min = nums2[j];
          }
          else if (j == n)
          {
            right_min = nums1[i];
          }
          else
          {
            right_min = std::min(nums1[i], nums2[j]);
          }
          return (left_max + right_min) / 2.0;
        }
      }
    }
    return 0.0;
  }
};

int main()
{
  Solution solution;
  std::cout << solution.findMedianSortedArrays({1, 3}, {2}) << std::endl;
  return 0;
}
