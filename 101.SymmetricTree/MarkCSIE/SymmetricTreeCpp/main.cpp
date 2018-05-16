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
  bool isSymmetric(TreeNode* root)
  {
    if (!root)
    {
      return true;
    }
    return checkSymmetric(root->left, root->right);
  }
protected:
  bool checkSymmetric(TreeNode* left, TreeNode* right)
  {
    if (!left && !right)
    {
      return true;
    }
    if (left && right)
    {
      return (left->val == right->val) && checkSymmetric(left->right, right->left) && checkSymmetric(right->right, left->left);
    }

    return false;
  }
};

int main()
{
  Solution solution;
  TreeNode node1(1);
  TreeNode node2(2);
  TreeNode node3(2);
  TreeNode node4(3);
  TreeNode node5(4);
  TreeNode node6(4);
  TreeNode node7(3);
  node1.left = &node2;
  node1.right = &node3;
  node2.left = &node4;
  node2.right = &node5;
  node3.left = &node6;
  node3.right = &node7;

  std::cout << solution.isSymmetric(&node1) << std::endl;

  return 0;
}
