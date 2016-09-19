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

    int sumNumbers(const TreeNode* root) {
        return DFS(root, "");
    }

    int DFS(const TreeNode* root, const std::string number_str) {
        if (root == nullptr) {
            return 0;
        }

        if (root->left == nullptr && root->right == nullptr) {
            if (!number_str.empty()) {
                return std::stoi(number_str) * 10 + root->val;
            } else {
                return root->val;
            }
        }

        int answer = 0;
        if (root->left != nullptr) {
            answer += DFS(root->left, number_str + std::to_string(root->val));
        }

        if (root->right != nullptr) {
            answer += DFS(root->right, number_str + std::to_string(root->val));
        }

        return answer;
    }
};

int main() {
    TreeNode *test = new TreeNode(1);
    test->left = new TreeNode(2);
    test->right = new TreeNode(3);

    Solution solution;
    std::cout << solution.sumNumbers(test) << std::endl;

    delete test->right;
    delete test->left;
    delete test;
    return 0;
}

