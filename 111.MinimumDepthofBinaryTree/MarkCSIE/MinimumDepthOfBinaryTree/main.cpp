#include <queue>
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

    int minDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int depth = 1;
        int pop_count = 0;
        int count = 1;
        int next_count = 0;
        std::queue<TreeNode*> node_queue; // BFS
        node_queue.push(root);
        while (!node_queue.empty()) {
            TreeNode* current_node = node_queue.front();
            if (current_node->left == nullptr && current_node->right == nullptr) {
                return depth;
            }

            node_queue.pop();
            pop_count++;
            if (current_node->left != nullptr) {
                node_queue.push(current_node->left);
                next_count++;
            }
            if (current_node->right != nullptr) {
                node_queue.push(current_node->right);
                next_count++;
            }

            if (pop_count == count) {
                count = next_count;
                next_count = 0;
                pop_count = 0;
                depth++;
            }
        }
        return 0;
    }
};

int main() {
    Solution solution;

    TreeNode *test = new TreeNode(1);
    test->right = new TreeNode(2);
    test->right->left = new TreeNode(3);

    std::cout << solution.minDepth(test) << std::endl;

    delete test->right->left;
    delete test->right;
    delete test;

    return 0;
}

