#include <iostream>

// Definition for a binary tree node.
struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(const int &x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
  int countNodes(TreeNode* const root)
  {
    TreeNode* curr_node = root;
    unsigned int left_depth = 0;
    while (curr_node != nullptr)
    {
      curr_node = curr_node->left;
      left_depth++;
    }

    curr_node = root;
    unsigned int right_depth = 0;
    while (curr_node != nullptr)
    {
      curr_node = curr_node->right;
      right_depth++;
    }

    if (left_depth == right_depth)
    {
      // 2^0 + 2^1 + ... + 2^{depth - 1} = 2^{depth} - 1
      return (1 << left_depth) - 1;
    }
    else
    {
      return countNodes(root->left) + countNodes(root->right) + 1;
    }
  }
};

int main()
{
  Solution solution;

  TreeNode *test = new TreeNode(1);
  test->left = new TreeNode(2);

  std::cout << solution.countNodes(test) << std::endl;

  delete test->left;
  delete test;
  return 0;
}
