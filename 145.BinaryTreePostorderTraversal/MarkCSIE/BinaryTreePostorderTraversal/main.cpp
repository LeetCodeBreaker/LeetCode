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

    std::vector<int> postorderTraversal(TreeNode* root) {
        std::vector<int> answer;
        if (root) {
            //            if (root->left) {
            //                std::vector<int> sub_answer = postorderTraversal(root->left);
            //                answer.insert(std::end(answer), std::begin(sub_answer), std::end(sub_answer));
            //            }
            //            if (root->right) {
            //                std::vector<int> sub_answer = postorderTraversal(root->right);
            //                answer.insert(std::end(answer), std::begin(sub_answer), std::end(sub_answer));
            //            }
            //            answer.push_back(root->val);
            
            
            std::stack<TreeNode*> nodeStack;
            nodeStack.push(root);
            TreeNode* head = root;
            while (!nodeStack.empty()) {
                TreeNode* top = nodeStack.top();
                if ((top->left == NULL && top->right == NULL) || top->right == head || top->left == head) {
                    answer.push_back(top->val);
                    nodeStack.pop();
                    head = top;
                } else {
                    if (top->right != NULL) {
                        nodeStack.push(top->right);
                    }
                    if (top->left != NULL) {
                        nodeStack.push(top->left);
                    }
                }
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

    std::vector<int> answer = solution.postorderTraversal(test);
    for (int i : answer) {
        std::cout << i << std::endl;
    }

    delete test->right->left;
    delete test->right;
    delete test;

    return 0;
}