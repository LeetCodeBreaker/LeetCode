#include <iostream>

// Definition for a binary tree node.

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(const int &x) : val(x), left(nullptr), right(nullptr) {
    }
};

class Solution {
public:

    bool hasPathSum(const TreeNode* root, const int &sum) {
        if (root == nullptr) {
            return false;
        }
        if (root->left == nullptr && root->right == nullptr) {
            return (sum - root->val) == 0;
        } else {
            if (hasPathSum(root->left, sum - root->val)) {
                return true;
            }
            if (hasPathSum(root->right, sum - root->val)) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    TreeNode *test = new TreeNode(5);

    test->left = new TreeNode(4);
    test->right = new TreeNode(8);

    test->left->left = new TreeNode(11);
    test->right->left = new TreeNode(13);
    test->right->right = new TreeNode(4);

    test->left->left->left = new TreeNode(7);
    test->left->left->right = new TreeNode(2);
    test->right->right->right = new TreeNode(1);

    Solution solution;
    std::cout << std::boolalpha << solution.hasPathSum(test, 22) << std::endl;

    delete test->left->left->left;
    delete test->left->left->right;
    delete test->right->right->right;

    delete test->left->left;
    delete test->right->left;
    delete test->right->right;

    delete test->left;
    delete test->right;

    delete test;
    return 0;
}

