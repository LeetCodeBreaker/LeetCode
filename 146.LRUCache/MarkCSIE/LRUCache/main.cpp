#include <iostream>
#include <list>
#include <unordered_map>

class LRUCache
{
public:
  LRUCache(const size_t& capacity) : capacity(capacity)
  {

  }

  int get(const int& key)
  {
    if (data.find(key) != data.end())
    {
      l.erase(data[key].second);
      l.emplace_back(key);
      data[key] = {data[key].first, --l.cend()};
      return data[key].first;
    }
    else
    {
      return -1;
    }
  }

  void put(const int& key, const int& value)
  {
    if (data.find(key) != data.end())
    {
      l.erase(data[key].second);
    }
    else
    {
      if (l.size() == capacity)
      {
        data.erase(l.front());
        l.pop_front();
      }
    }
    l.emplace_back(key);
    data[key] = {value, --l.cend()};
  }
protected:
  std::list<int> l;
  std::unordered_map<int, std::pair<int, std::list<int>::const_iterator>> data;
  size_t capacity;

};

int main()
{
  LRUCache cache(2);

  cache.put(1, 1);
  cache.put(2, 2);
  std::cout << cache.get(1) << std::endl; // returns 1
  cache.put(3, 3);                        // evicts key 2
  std::cout << cache.get(2) << std::endl; // returns -1 (not found)
  cache.put(4, 4);                        // evicts key 1
  std::cout << cache.get(1) << std::endl; // returns -1 (not found)
  std::cout << cache.get(3) << std::endl; // returns 3
  std::cout << cache.get(4) << std::endl; // returns 4
  return 0;
}
