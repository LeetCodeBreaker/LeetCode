#include <iostream>
#include <vector>
#include <unordered_map>

class Solution
{
public:
  std::vector<int> findSubstring(const std::string& s, const std::vector<std::string>& words)
  {
    std::vector<int> answer;

    size_t word_length = words[0].length();
    if (s.length() < word_length)
    {
      return answer;
    }
    size_t num_words = words.size();

    std::unordered_map<std::string, int> count_map;
    for (size_t i = 0; i < num_words; ++i)
    {
      ++count_map[words[i]];
    }

    for (size_t i = 0; i < word_length; ++i)
    {
      std::unordered_map<std::string, int> temp_count_map;
      unsigned int left = i;
      size_t count = 0;
      for (size_t j = i; j <= s.length() - word_length; j += word_length)
      {
        std::string word = s.substr(j, word_length);

        if (count_map[word] > 0)
        {
          ++temp_count_map[word];
          if (temp_count_map[word] <= count_map[word])
          {
            ++count;
          }
          else
          {
            while (temp_count_map[word] > count_map[word])
            {
              std::string word1 = s.substr(left, word_length);
              --temp_count_map[word1];
              left += word_length;
              if (temp_count_map[word1] < count_map[word1])
              {
                --count;
              }
            }
          }
          if (count == num_words)
          {
            answer.push_back(left);
            --temp_count_map[s.substr(left, word_length)];
            --count;
            left += word_length;
          }
        }
        else
        {
          temp_count_map.clear();
          count = 0;
          left = j + word_length;
        }
      }
    }
    return answer;
  }
};

int main()
{
  Solution solution;
  for (const int& i : solution.findSubstring("barfoothefoobarman", {"foo", "bar"}))
  {
    std::cout << i << std::endl;
  }
  return 0;
}
