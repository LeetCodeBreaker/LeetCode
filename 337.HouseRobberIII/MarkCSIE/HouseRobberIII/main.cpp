#include <iostream>
#include <utility>

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class Solution {
public:
  int rob(const TreeNode* root)
  {
    std::pair<int, int> results = rob2(root);
    return std::max(results.first, results.second);
  }

  std::pair<int, int> rob2(const TreeNode* root)
  {
    std::pair<int, int> results(0, 0);
    if (root == nullptr)
    {
      return results;
    }

    std::pair<int, int> left_results = rob2(root->left);
    std::pair<int, int> right_results = rob2(root->right);

    results.first = root->val + left_results.second + right_results.second;
    results.second = std::max(left_results.first, left_results.second) + std::max(right_results.first, right_results.second);

    return results;
  }
};

int main()
{
  TreeNode* test = new TreeNode(3);
  test->left = new TreeNode(2);
  test->right = new TreeNode(3);
  test->left->right = new TreeNode(3);
  test->right->right = new TreeNode(1);

  Solution solution;
  std::cout << solution.rob(test) << std::endl;

  delete test->right->right;
  delete test->left->right;
  delete test->right;
  delete test->left;
  delete test;
  return 0;
}
