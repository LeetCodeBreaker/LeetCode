#include <iostream>

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
  int pathSum(const TreeNode* root, const int &sum)
  {
    if (root == nullptr)
    {
      return 0;
    }

    return (root->val == sum)
        + pathSum(root->left, sum) + pathSum(root->right, sum)
        + pathSumRoot(root->left, sum - root->val) + pathSumRoot(root->right, sum - root->val);

    // TODO: O(n) solution ??
  }

  int pathSumRoot(const TreeNode* root, const int &sum)
  {
    if (root == nullptr)
    {
      return 0;
    }
    return (root->val == sum)
        + pathSumRoot(root->left, sum - root->val) + pathSumRoot(root->right, sum - root->val);
  }
};

int main()
{
  TreeNode* test = new TreeNode(10);
  test->left = new TreeNode(5);
  test->right = new TreeNode(-3);
  test->left->left = new TreeNode(3);
  test->left->right = new TreeNode(2);
  test->right->right = new TreeNode(11);
  test->left->left->left = new TreeNode(3);
  test->left->left->right = new TreeNode(-2);
  test->left->right->right = new TreeNode(1);

  Solution solution;
  std::cout << solution.pathSum(test, 8) << std::endl;

  delete test->left->right->right;
  delete test->left->left->right;
  delete test->left->left->left;
  delete test->right->right;
  delete test->left->right;
  delete test->left->left;
  delete test->right;
  delete test->left;
  delete test;

  return 0;
}
