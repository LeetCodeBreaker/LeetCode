#include <iostream>
#include <vector>
#include <queue>

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
    std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root) {
        std::vector<std::vector<int>> answer;
        if (!root) {
            return answer;
        }

        std::queue<TreeNode *> node_queue;
        node_queue.push(root);
        unsigned int count = 1;
        unsigned int next_count = 0;
        bool zig = true;

        std::vector<int> node_vector;
        while (!node_queue.empty()) {
            TreeNode *current_node = node_queue.front();
            node_queue.pop();
            if (zig) {
                node_vector.push_back(current_node->val);
            } else {
                node_vector.insert(node_vector.begin(), current_node->val);
            }
            
            if (current_node->left) {
                node_queue.push(current_node->left);
                next_count++;
            }
            if (current_node->right) {
                node_queue.push(current_node->right);
                next_count++;
            }

            if (count == node_vector.size()) {
                answer.push_back(node_vector);
                count = next_count;
                node_vector.clear();
                next_count = 0;
                zig = !zig;
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

    std::vector<std::vector<int>> answer = solution.zigzagLevelOrder(test);
    for (std::vector<int> v : answer) {
        for (int i : v) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }

    delete test->right->left;
    delete test->right;
    delete test;

    return 0;
}

