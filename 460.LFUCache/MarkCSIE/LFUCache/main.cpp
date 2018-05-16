#include <iostream>
#include <list>
#include <unordered_map>

class LFUCache
{
public:
  LFUCache(const size_t& capacity) : capacity(capacity), min_freq(0)
  {

  }

  int get(const int& key)
  {
    if (data.find(key) != data.cend())
    {
      freq[data[key].second].erase(iters[key]);
      if (freq[min_freq].size() == 0)
      {
        ++min_freq;
      }

      ++data[key].second;
      freq[data[key].second].emplace_back(key);
      iters[key] = --freq[data[key].second].cend();
      return data[key].first;
    }
    else
    {
      return -1;
    }
  }

  void put(const int& key, const int& value)
  {
    if (capacity == 0)
    {
      return;
    }

    if (data.find(key) != data.cend())
    {
      data[key].first = value;
      freq[data[key].second].erase(iters[key]);
      if (freq[min_freq].size() == 0)
      {
        ++min_freq;
      }
      ++data[key].second;
    }
    else
    {
      if (data.size() == capacity)
      {
        data.erase(freq[min_freq].front());
        freq[min_freq].pop_front();
      }
      data[key] = {value, 1};
      min_freq = 1;
    }
    freq[data[key].second].emplace_back(key);
    iters[key] = --freq[data[key].second].cend();
  }
protected:
  std::unordered_map<int, std::pair<int, int>> data;
  std::unordered_map<int, std::list<int>::const_iterator> iters;
  std::unordered_map<int, std::list<int>> freq;
  size_t capacity;
  int min_freq;
};

int main()
{
  LFUCache cache(2);

  cache.put(1, 1);
  cache.put(2, 2);
  std::cout << cache.get(1) << std::endl; // returns 1
  cache.put(3, 3);                        // evicts key 2
  std::cout << cache.get(2) << std::endl; // returns -1 (not found)
  std::cout << cache.get(3) << std::endl; // returns 3
  cache.put(4, 4);                        // evicts key 1
  std::cout << cache.get(1) << std::endl; // returns -1 (not found)
  std::cout << cache.get(3) << std::endl; // returns 3
  std::cout << cache.get(4) << std::endl; // returns 4
  return 0;
}
