#include <vector>

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

    std::vector<TreeNode *> generateTrees(int n) {
        std::vector<TreeNode*> answer;
        if (n > 0) {
            answer = recursive(1, n);
        }
        return answer;
    }

    std::vector<TreeNode *> recursive(int min, int max) {
        std::vector<TreeNode*> answer;
        if (min > max) {
            answer.push_back(nullptr);
            return answer;
        }
        for (int i = min; i <= max; i++) {
            std::vector<TreeNode*> leftTrees = recursive(min, i - 1);
            std::vector<TreeNode*> rightTrees = recursive(i + 1, max);
            for (int j = 0; j < leftTrees.size(); j++) {
                for (int k = 0; k < rightTrees.size(); k++) {
                    TreeNode *head = new TreeNode(i);
                    head->left = leftTrees[j];
                    head->right = rightTrees[k];
                    answer.push_back(head);
                }
            }
        }
        return answer;
    }
};

int main() {
    Solution solution;

    std::vector<TreeNode*> answer = solution.generateTrees(3);

    return 0;
}

