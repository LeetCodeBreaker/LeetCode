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
public:
  bool isBalanced(TreeNode* root)
  {
    if (height(root) == -2)
    {
      return false;
    }
    else
    {
      return true;
    }
  }
protected:
  int height(TreeNode* root)
  {
    if (root == nullptr)
    {
      return -1;
    }
    int left_height = height(root->left);
    if (left_height == -2)
    {
      return -2;
    }
    int right_height = height(root->right);
    if (right_height == -2)
    {
      return -2;
    }
    if (std::abs(left_height - right_height) > 1)
    {
      return -2;
    }
    return std::max(left_height, right_height) + 1;
  }
};

int main()
{
  TreeNode *test = new TreeNode(1);
  test->left = new TreeNode(2);
  test->right = new TreeNode(3);
  test->left->left = new TreeNode(4);

  Solution solution;
  std::cout << solution.isBalanced(test) << std::endl;

  delete test->left->left;
  delete test->right;
  delete test->left;
  delete test;
}
