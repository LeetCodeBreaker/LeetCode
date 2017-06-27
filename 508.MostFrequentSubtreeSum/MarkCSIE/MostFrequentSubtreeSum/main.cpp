#include <iostream>
#include <unordered_map>
#include <vector>

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(const int &x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
protected:
  std::unordered_map<int, unsigned int> frequency_map;
public:
  std::vector<int> findFrequentTreeSum(const TreeNode* const root)
  {
    frequency_map.clear();
    subTreeSum(root);

    std::vector<int> answer;
    unsigned int max = 0;
    for (std::unordered_map<int, unsigned int>::const_iterator it = frequency_map.begin(); it != frequency_map.end(); ++it)
    {
      if (it->second > max)
      {
        answer.clear();
        answer.push_back(it->first);
        max = it->second;
      }
      else if (it->second == max)
      {
        answer.push_back(it->first);
      }
    }
    return answer;
  }

protected:
  int subTreeSum(const TreeNode* const root)
  {
    if (root == nullptr)
    {
      return 0;
    }

    int sum = root->val + subTreeSum(root->left) + subTreeSum(root->right);
    ++frequency_map[sum];
    return sum;
  }
};

int main()
{
  TreeNode *test = new TreeNode(5);
  test->left = new TreeNode(2);
  test->right = new TreeNode(-3);

  Solution solution;
  for (const int &i : solution.findFrequentTreeSum(test))
  {
    std::cout << i << std::endl;
  }

  delete test->right;
  delete test->left;
  delete test;
  return 0;
}
