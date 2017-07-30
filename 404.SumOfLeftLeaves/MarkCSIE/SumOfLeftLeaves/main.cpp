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
  int dfsLeaves(const TreeNode* const root, const bool &left)
  {
    if (root == nullptr)
    {
      return 0;
    }

    if (root->left == nullptr && root->right == nullptr && left)
    {
      return root->val;
    }
    else
    {
      return dfsLeaves(root->left, true) + dfsLeaves(root->right, false);
    }
  }
public:
  int sumOfLeftLeaves(TreeNode* root)
  {
    return dfsLeaves(root, false);
  }
};

int main()
{
  Solution solution;

  TreeNode *test = new TreeNode(3);
  test->left = new TreeNode(9);
  test->right = new TreeNode(20);
  test->right->left = new TreeNode(15);
  test->right->right = new TreeNode(7);

  std::cout << solution.sumOfLeftLeaves(test) << std::endl;

  delete test->right->right;
  delete test->right->left;
  delete test->right;
  delete test->left;
  delete test;
  return 0;
}
