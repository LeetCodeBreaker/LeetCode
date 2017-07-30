#include <iostream>

bool isBadVersion(int version)
{
  if (version >= 2)
  {
    return true;
  }
  else
  {
    return false;
  }
}

class Solution
{
public:
  int firstBadVersion(const int &n)
  {
    // binary search
    int lower = 1;
    int higher = n;
    while (lower <= higher)
    {
      int mid = lower + (higher - lower) / 2;
      if (isBadVersion(mid))
      {
        higher = mid - 1;
      }
      else
      {
        lower = mid + 1;
      }
    }
    return lower;
  }
};

int main()
{
  Solution solution;
  std::cout << solution.firstBadVersion(2) << std::endl;
  return 0;
}
