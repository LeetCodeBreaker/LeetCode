#include <iostream>

// Definition for a binary tree node.

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
    }
};

class Solution {
public:

    bool isValidBST(TreeNode* root) {
        if (root) {
            recursive(root, LLONG_MAX, LLONG_MIN);
        }
    }

    bool recursive(TreeNode* root, long long int max, long long int min) {
        if (root->left) {
            if (root->left->val >= root->val || root->left->val <= min || !recursive(root->left, root->val, min)) {
                return false;
            }
        }
        if (root->right) {
            if (root->right->val <= root->val || root->right->val >= max || !recursive(root->right, max, root->val)) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution solution;

    TreeNode *test = new TreeNode(1);
    test->right = new TreeNode(2);
    test->right->left = new TreeNode(3);

    std::cout << solution.isValidBST(test) << std::endl;

    delete test->right->left;
    delete test->right;
    delete test;

    return 0;
}

