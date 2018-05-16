#include <iostream>

// Definition for a binary tree node.
struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(const int& x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
  void recoverTree(TreeNode* root)
  {
    // Morris inorder traversal
    TreeNode* current = root;
    TreeNode* pre = nullptr;
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
    while (current != nullptr)
    {
      if (current->left == nullptr)
      {
        // visiting a node
        std::cout << current->val << " ";
        if (pre != nullptr && pre->val > current->val)
        {
          if (first == nullptr)
          {
            first = pre;
            second = current;
          }
          else
          {
            second = current;
          }
        }
        pre = current;
        current = current->right;
      }
      else
      {
        TreeNode* predecessor = current->left;
        while (predecessor->right != current && predecessor->right != nullptr)
        {
          predecessor = predecessor->right;
        }
        if (predecessor->right == nullptr)
        {
          predecessor->right = current;
          current = current->left;
        }
        else
        {
          // visiting a node
          std::cout << current->val << " ";
          if (pre != nullptr && pre->val > current->val)
          {
            if (first == nullptr)
            {
              first = pre;
              second = current;
            }
            else
            {
              second = current;
            }
          }
          predecessor->right = nullptr;
          pre = current;
          current = current->right;
        }
      }
    }

    // swap two node values;
    if (first != nullptr && second != nullptr)
    {
      std::swap(first->val, second->val);
    }
    std::cout << std::endl;
  }
};

int main()
{
  Solution solution;

  TreeNode *test = new TreeNode(1);
  test->left = new TreeNode(3);
  test->left->right = new TreeNode(2);

  solution.recoverTree(test);
  solution.recoverTree(test);

  delete test->left->right;
  delete test->left;
  delete test;
  return 0;
}
