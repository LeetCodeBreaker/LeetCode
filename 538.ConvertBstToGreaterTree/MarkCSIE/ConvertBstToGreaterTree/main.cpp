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
  TreeNode* convertBST(TreeNode* const root)
  {
    recursive(root, 0);
    return root;

  }
protected:
  int recursive(TreeNode* const root, const int& sum)
  {
    if (root != nullptr)
    {
      int right_sum = recursive(root->right, sum);
      root->val = root->val + right_sum;
      return recursive(root->left, root->val);
    }
    else
    {
      return sum;
    }
  }
};

int main()
{
  Solution solution;

  TreeNode *test = new TreeNode(2);
  test->left = new TreeNode(2);
  test->right = new TreeNode(3);

  solution.convertBST(test);

  delete test->right;
  delete test->left;
  delete test;
}
