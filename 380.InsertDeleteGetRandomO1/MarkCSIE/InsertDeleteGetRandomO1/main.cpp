#include <iostream>
#include <unordered_map>
#include <vector>

class RandomizedSet
{
protected:
  std::unordered_map<int, size_t> index_map;
  std::vector<int> data;
public:
  /** Initialize your data structure here. */
  RandomizedSet()
  {

  }

  /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
  bool insert(const int& val)
  {
    if (index_map.find(val) != index_map.end())
    {
      return false;
    }
    else
    {
      data.push_back(val);
      index_map[val] = data.size() - 1;
      return true;
    }
  }

  /** Removes a value from the set. Returns true if the set contained the specified element. */
  bool remove(const int& val)
  {
    if (index_map.find(val) == index_map.end())
    {
      return false;
    }
    else
    {
      data[index_map[val]] = data.back();
      index_map[data.back()] = index_map[val];
      data.pop_back();
      index_map.erase(val);
      return true;
    }

  }

  /** Get a random element from the set. */
  int getRandom()
  {
    return data[rand() % data.size()];
  }
};

int main()
{
  RandomizedSet randomSet;

  // Inserts 1 to the set. Returns true as 1 was inserted successfully.
  std::cout << randomSet.insert(1) << std::endl;
  // Returns false as 2 does not exist in the set.
  std::cout << randomSet.remove(2) << std::endl;
  // Inserts 2 to the set, returns true. Set now contains [1,2].
  std::cout << randomSet.insert(2) << std::endl;
  // getRandom should return either 1 or 2 randomly.
  std::cout << randomSet.getRandom() << std::endl;
  // Removes 1 from the set, returns true. Set now contains [2].
  std::cout << randomSet.remove(1) << std::endl;
  // 2 was already in the set, so return false.
  std::cout << randomSet.insert(2) << std::endl;
  // Since 2 is the only number in the set, getRandom always return 2.
  std::cout << randomSet.getRandom() << std::endl;

  return 0;
}
