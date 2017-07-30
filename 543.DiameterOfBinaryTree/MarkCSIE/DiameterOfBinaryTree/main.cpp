#include <iostream>

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
protected:
  int dfsMax(const TreeNode * const root, int &max)
  {
    if (root == nullptr)
    {
      return 0;
    }

    int left_max = dfsMax(root->left, max);
    int right_max = dfsMax(root->right, max);
    max = std::max(left_max + right_max, max);

    return 1 + std::max(left_max, right_max);
  }
public:
  int diameterOfBinaryTree(const TreeNode * const root)
  {
    int max = 0;
    dfsMax(root, max);
    return max;
  }
};

int main()
{
  Solution solution;

  TreeNode *test = new TreeNode(1);
  test->left = new TreeNode(2);
  test->right = new TreeNode(3);
  test->left->left = new TreeNode(4);
  test->left->right = new TreeNode(5);

  std::cout << solution.diameterOfBinaryTree(test) << std::endl;

  delete test->left->right;
  delete test->left->left;
  delete test->right;
  delete test->left;
  delete test;
  return 0;
}
