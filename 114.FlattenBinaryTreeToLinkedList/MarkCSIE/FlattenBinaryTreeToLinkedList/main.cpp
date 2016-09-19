#include <iostream>

//  Definition for a binary tree node.

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
    }
};

class Solution {
public:

    void flatten(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        flatten(root->right);

        if (root->left != nullptr) {
            flatten(root->left);
            TreeNode* curr_node = root->left;
            while (curr_node->right != nullptr) {
                curr_node = curr_node->right;
            }
            curr_node->right = root->right;
            root->right = root->left;
            root->left = nullptr;
        }
        return;
    }
};

int main() {
    TreeNode *test = new TreeNode(1);
    test->left = new TreeNode(2);
    test->left->left = new TreeNode(3);
    test->left->right = new TreeNode(4);
    test->right = new TreeNode(5);
    test->right->right = new TreeNode(6);

    Solution solution;
    solution.flatten(test);
    TreeNode* curr_node = test;
    while (curr_node != nullptr) {
        std::cout << curr_node->val << std::endl;
        TreeNode* temp_node = curr_node;
        curr_node = curr_node->right;
        delete temp_node;
    }
    return 0;
}

