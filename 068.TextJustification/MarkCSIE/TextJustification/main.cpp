#include <iostream>
#include <vector>

class Solution
{
public:
  std::vector<std::string> fullJustify(const std::vector<std::string>& words, const int& maxWidth)
  {
    std::vector<std::string> answer;
    std::vector<std::string> candidate_words;
    int words_length = 0;
    for (size_t i = 0; i < words.size(); ++i)
    {
      if (words_length + candidate_words.size() + words[i].length() > maxWidth)
      {
        int spaces = maxWidth - words_length;
        int divisor = std::max(static_cast<int>(candidate_words.size()) - 1, 1);
        int space = spaces / divisor;
        int remain = spaces % divisor;
        std::string line = "";
        for (size_t j = 0; j < candidate_words.size(); ++j)
        {
          line += candidate_words[j];
          if (j < candidate_words.size() - 1 || candidate_words.size() == 1)
          {
            line += std::string(space, ' ');
          }
          if (remain > 0)
          {
            line += " ";
            --remain;
          }
        }
        answer.push_back(line);
        candidate_words.clear();
        words_length = 0;
      }
      words_length += words[i].length();
      candidate_words.push_back(words[i]);
    }

    if (!candidate_words.empty())
    {
      std::string line = "";
      for (const std::string& s : candidate_words)
      {
        line += s + " ";
      }
      while (line.length() > maxWidth)
      {
        line.pop_back();
      }
      while (line.length() < maxWidth)
      {
        line += " ";
      }
      answer.push_back(line);
    }

    return answer;
  }
};

int main()
{
  Solution solution;
  for (const std::string& s : solution.fullJustify({"This", "is", "an", "example", "of", "text", "justification."}, 16))
  {
    std::cout << s << std::endl;
  }
  return 0;
}
