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

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) {
            return true;
        }

        if (p && q && p->val == q->val) {
            if (!isSameTree(p->left, q->left)) {
                return false;
            }
            if (!isSameTree(p->right, q->right)) {
                return false;
            }
        } else {
            return false;
        }

        return true;
    }
};

int main() {
    Solution solution;

    TreeNode *test = new TreeNode(1);
    test->right = new TreeNode(2);
    test->right->left = new TreeNode(3);

    std::cout << solution.isSameTree(test, test) << std::endl;

    delete test->right->left;
    delete test->right;
    delete test;

    return 0;
}

