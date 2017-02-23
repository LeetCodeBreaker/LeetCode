#include <iostream>
#include <vector>

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
  std::vector<std::string> binaryTreePaths(const TreeNode* root) {
    std::vector<std::string> result;
    if (root == nullptr)
    {
      return result;
    }

    if (root->left == nullptr && root->right == nullptr)
    {
      result.push_back(std::to_string(root->val));
    }
    else
    {
      if (root->left != nullptr)
      {
        for (const std::string &s : binaryTreePaths(root->left))
        {
          result.push_back(std::to_string(root->val) + "->" + s);
        }
      }

      if (root->right != nullptr)
      {
        for (const std::string &s : binaryTreePaths(root->right))
        {
          result.push_back(std::to_string(root->val) + "->" + s);
        }
      }
    }
    return result;
  }
};

int main()
{
  TreeNode* test = new TreeNode(1);
  test->left = new TreeNode(2);
  test->right = new TreeNode(3);
  test->left->right = new TreeNode(5);

  Solution solution;
  for (const std::string &s : solution.binaryTreePaths(test))
  {
    std::cout << s << std::endl;
  }

  delete test->left->right;
  delete test->right;
  delete test->left;
  delete test;

  return 0;
}
