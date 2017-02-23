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
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
  {
    if (root == nullptr)
    {
      return nullptr;
    }

    if (root->val <= p->val && root->val >= q->val || root->val >= p->val && root->val <= q->val)
    {
      return root;
    }
    else if (root->val > p->val && root->val > q->val)
    {
      return lowestCommonAncestor(root->left, p, q);
    }
    else
    {
      return lowestCommonAncestor(root->right, p, q);
    }

  }
};

int main()
{
  TreeNode* test = new TreeNode(6);
  test->left = new TreeNode(2);
  test->right = new TreeNode(8);
  test->left->left = new TreeNode(0);
  test->left->right = new TreeNode(4);
  test->right->left = new TreeNode(7);
  test->right->right = new TreeNode(9);

  Solution solution;
  TreeNode* answer = solution.lowestCommonAncestor(test, test->left, test->right);
  std::cout << answer->val << std::endl;

  delete test->right->right;
  delete test->right->left;
  delete test->left->right;
  delete test->left->left;
  delete test->right;
  delete test->left;
  delete test;
  return 0;
}
