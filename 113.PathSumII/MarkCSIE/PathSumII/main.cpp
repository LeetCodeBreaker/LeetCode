#include <iostream>
#include <vector>

//  Definition for a binary tree node.
struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
  std::vector<std::vector<int>> pathSum(TreeNode* root, int sum)
  {
    std::vector<std::vector<int>> results;
    if (root == nullptr)
    {
      return results;
    }

    if (root->left == nullptr && root->right == nullptr)
    {
      if (sum == root->val)
      {
        results.push_back({root->val});
      }
    }
    else
    {
      for (std::vector<int> &v : pathSum(root->left, sum - root->val))
      {
        v.insert(v.begin(), root->val);
        results.push_back(v);
      }

      for (std::vector<int> &v : pathSum(root->right, sum - root->val))
      {
        v.insert(v.begin(), root->val);
        results.push_back(v);
      }
    }
    return results;
  }
};

int main()
{
  TreeNode* test = new TreeNode(5);
  test->left = new TreeNode(4);
  test->right = new TreeNode(8);
  test->left->left = new TreeNode(11);
  test->right->left = new TreeNode(13);
  test->right->right = new TreeNode(4);
  test->left->left->left = new TreeNode(7);
  test->left->left->right = new TreeNode(2);
  test->right->right->left = new TreeNode(5);
  test->right->right->right = new TreeNode(1);

  Solution solution;
  for (const std::vector<int> &v : solution.pathSum(test, 22))
  {
    for (const int &i : v)
    {
      std::cout << i << " ";
    }
    std::cout << std::endl;
  }

  delete test->right->right->right;
  delete test->right->right->left;
  delete test->left->left->right;
  delete test->left->left->left;
  delete test->right->right;
  delete test->right->left;
  delete test->left->left;
  delete test->right;
  delete test->left;
  delete test;

  return 0;
}
