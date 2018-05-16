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
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
  {
    if (root == nullptr || root == p || root == q)
    {
      return root;
    }
    TreeNode* left_lca = lowestCommonAncestor(root->left, p, q);
    TreeNode* right_lca = lowestCommonAncestor(root->right, p, q);
    if (left_lca && right_lca)
    {
      return root;
    }
    else if (left_lca)
    {
      return left_lca;
    }
    else if (right_lca)
    {
      return right_lca;
    }
    return nullptr;
  }
};

int main()
{
  TreeNode *test = new TreeNode(1);
  test->left = new TreeNode(2);
  test->right = new TreeNode(3);
  test->left->left = new TreeNode(4);

  Solution solution;
  std::cout << solution.lowestCommonAncestor(test, test->left, test->left->left)->val << std::endl;

  delete test->left->left;
  delete test->right;
  delete test->left;
  delete test;
}
