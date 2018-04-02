#include <iostream>
#include <vector>
#include <algorithm>

// Definition for an interval.
struct Interval
{
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(const int &s, const int &e) : start(s), end(e) {}
};

class Solution
{
public:
  int eraseOverlapIntervals(std::vector<Interval> intervals)
  {
    // Same as "Interval Scheduling" problem
    // Greedy approach
    std::sort(intervals.begin(), intervals.end(), compare);
    int remove_count = 0;
    size_t i = 0;
    while (i < intervals.size())
    {
      size_t j = i + 1;
      while (j < intervals.size())
      {
        if (intervals[j].start < intervals[i].end)
        {
          remove_count++;
        }
        else
        {
          break;
        }
        j++;
      }
      i = j;
    }
    return remove_count;
  }
protected:
  static bool compare(const Interval &i1, const Interval &i2)
  {
    return i1.end < i2.end;
  }
};

int main()
{
  Solution solution;
  std::vector<Interval> test;
  test.push_back(Interval(1, 2));
  test.push_back(Interval(2, 3));
  test.push_back(Interval(3, 4));
  test.push_back(Interval(1, 3));
  std::cout << solution.eraseOverlapIntervals(test) << std::endl;
}
