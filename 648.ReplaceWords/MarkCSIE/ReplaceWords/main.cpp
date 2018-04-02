#include <iostream>
#include <vector>
#include <memory>
#include <sstream>
#include <iterator>
#include <unordered_map>

class Trie
{
protected:
  class TrieNode
  {
  public:
    typedef std::shared_ptr<TrieNode> Ptr;
    std::unordered_map<char, Ptr> children_;
    bool valid_;

    TrieNode() : valid_(false)
    {

    }
  };

  TrieNode::Ptr root_;
public:
  typedef std::shared_ptr<Trie> Ptr;
  Trie() : root_(new TrieNode())
  {

  }

  void addWord(const std::string &word)
  {
    TrieNode::Ptr current_node = root_;
    for (size_t i = 0; i < word.length(); ++i)
    {
      char c =  word[i];
      if (current_node->children_[c] == nullptr)
      {
        current_node->children_[c] = TrieNode::Ptr(new TrieNode());
      }
      else
      {
        if (current_node->children_[c]->valid_)
        {
          return;
        }
      }
      current_node = current_node->children_[c];
    }
    current_node->valid_ = true;
  }

  std::string getShortestPrefix(const std::string &word)
  {
    std::string prefix = "";
    TrieNode::Ptr current_node = root_;
    for (size_t i = 0; i < word.length(); ++i)
    {
      char c =  word[i];
      if (current_node->children_[c] == nullptr)
      {
        break;
      }
      else
      {
        current_node = current_node->children_[c];
        prefix = prefix + c;
        if (current_node->valid_)
        {
          return prefix;
        }
      }
    }
    return "";
  }
};

class Solution
{
public:
  std::string replaceWords(const std::vector<std::string>& dict, const std::string &sentence)
  {
    // Build a Trie
    Trie::Ptr trie = Trie::Ptr(new Trie());
    for (const std::string &word : dict)
    {
      trie->addWord(word);
    }

    std::istringstream iss(sentence);
    std::vector<std::string> tokens{std::istream_iterator<std::string>{iss},
                                    std::istream_iterator<std::string>{}};

    std::string answer = "";
    for (const std::string &word : tokens)
    {
      std::string shortest_prefix = trie->getShortestPrefix(word);
      if (shortest_prefix != "")
      {
        answer = answer + shortest_prefix + " ";
      }
      else
      {
        answer = answer + word + " ";
      }
    }

    answer.resize(answer.length() - 1);
    return answer;
  }
};

int main()
{
  Solution solution;
  std::cout << solution.replaceWords({"cat", "bat", "rat"}, "the cattle was rattled by the battery") << std::endl;
}
