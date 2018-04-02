#include <iostream>
#include <vector>

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
  std::vector<Interval> insert(const std::vector<Interval>& intervals, Interval newInterval)
  {
    std::vector<Interval> answer;
    size_t index = 0;

    while (index < intervals.size() && intervals[index].end < newInterval.start)
    {
      answer.push_back(intervals[index]);
      ++index;
    }

    while (index < intervals.size() && intervals[index].start <= newInterval.end)
    {
      newInterval.start = std::min(newInterval.start, intervals[index].start);
      newInterval.end = std::max(newInterval.end, intervals[index].end);
      ++index;
    }
    answer.push_back(newInterval);

    while (index < intervals.size())
    {
      answer.push_back(intervals[index]);
      ++index;
    }

    return answer;
  }
};

int main()
{
  Solution solution;
  std::vector<Interval> testcase1_1;
  testcase1_1.push_back(Interval(1, 3));
  testcase1_1.push_back(Interval(6, 9));
  Interval testcase1_2(2, 5);

  for (const Interval& interval : solution.insert(testcase1_1, testcase1_2))
  {
    std::cout << interval.start << " " << interval.end << std::endl;
  }

  return 0;
}
