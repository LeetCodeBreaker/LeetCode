#include <iostream>
#include <unordered_map>

// Definition for a binary tree node.
struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode(const int &x) : val(x), left(nullptr), right(nullptr)
  {
  }
};

class Solution
{

public:
  bool findTarget(const TreeNode* const root, const int& k)
  {
    std::unordered_map<int, bool> residual_map;
    return recursive(root, k, residual_map);
  }

protected:
  bool recursive(const TreeNode* const node, const int& k, std::unordered_map<int, bool>& residual_map)
  {
    if (node == nullptr)
    {
      return false;
    }
    if (residual_map[k - node->val])
    {
      return true;
    }
    else
    {
      residual_map[node->val] = true;
      if (recursive(node->left, k, residual_map))
      {
        return true;
      }
      else
      {
        return recursive(node->right, k, residual_map);
      }
    }
  }
};

int main()
{
  Solution solution;

  TreeNode *test = new TreeNode(5);
  test->left = new TreeNode(3);
  test->right = new TreeNode(6);
  test->left->left = new TreeNode(2);
  test->left->right = new TreeNode(4);

  std::cout << solution.findTarget(test, 9) << std::endl;

  delete test->left->right;
  delete test->left->left;
  delete test->right;
  delete test->left;
  delete test;
  return 0;
}
