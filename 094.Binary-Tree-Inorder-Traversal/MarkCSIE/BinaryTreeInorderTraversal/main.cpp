#include <iostream>
#include <vector>
#include <stack>

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

    std::vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> answer;
//        if (root) {
//            if (root->left) {
//                vector<int> sub_answer = inorderTraversal(root->left);
//                answer.insert(std::end(answer), std::begin(sub_answer), std::end(sub_answer));
//            }
//            answer.push_back(root->val);
//            if (root->right) {
//                vector<int> sub_answer = inorderTraversal(root->right);
//                answer.insert(std::end(answer), std::begin(sub_answer), std::end(sub_answer));
//            }
//        }

        std::stack<TreeNode *> nodeStack;
        TreeNode *current = root;
        while (!nodeStack.empty() || current) {
            if (current) {
                nodeStack.push(current);
                current = current->left;
            } else {
                current = nodeStack.top();
                nodeStack.pop();
                answer.push_back(current->val);
                current = current->right;
            }
        }
        return answer;
    }
};

int main() {
    Solution solution;

    TreeNode *test = new TreeNode(1);
    test->right = new TreeNode(2);
    test->right->left = new TreeNode(3);

    std::vector<int> answer = solution.inorderTraversal(test);
    for (int i : answer) {
        std::cout << i << std::endl;
    }

    delete test->right->left;
    delete test->right;
    delete test;

    return 0;
}