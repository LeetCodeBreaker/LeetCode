#include <iostream>
#include <vector>
#include <algorithm>

// Definition for an interval.
struct Interval
{
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(const int& s, const int& e) : start(s), end(e) {}
};

class Solution
{
public:
  std::vector<Interval> merge(std::vector<Interval> intervals)
  {
    std::sort(intervals.begin(), intervals.end(), compInterval);
    std::vector<Interval> answer;
    for (const Interval& interval : intervals)
    {
      if (answer.empty() || answer.back().end < interval.start)
      {
        answer.push_back(interval);
      }
      else
      {
        answer.back().end = std::max(answer.back().end, interval.end);
      }
    }
    return answer;
  }
protected:
  static bool compInterval (const Interval& i, const Interval& j)
  {
    return i.start < j.start;
  }
};

int main()
{
  Solution solution;
  std::vector<Interval> testcase1;
  testcase1.push_back(Interval(1, 3));
  testcase1.push_back(Interval(2, 6));
  testcase1.push_back(Interval(8, 10));
  testcase1.push_back(Interval(15, 18));

  for (const Interval& interval : solution.merge(testcase1))
  {
    std::cout << interval.start << " " << interval.end << std::endl;
  }

  return 0;
}
