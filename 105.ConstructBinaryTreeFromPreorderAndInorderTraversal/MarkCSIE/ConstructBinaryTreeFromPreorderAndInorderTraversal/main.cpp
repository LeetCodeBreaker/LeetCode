#include <iostream>
#include <algorithm>
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

    TreeNode* buildTree(const std::vector<int>& preorder, const std::vector<int>& inorder) {
        return recursive(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }

    TreeNode* recursive(const std::vector<int>& preorder, const std::vector<int>& inorder, const int &pre_begin, const int &pre_end, const int &in_begin, const int &in_end) {
        TreeNode* head = nullptr;
        
        if (pre_begin <= pre_end) {
            head = new TreeNode(preorder[pre_begin]);
            auto inorder_current = std::find(inorder.begin() + in_begin, inorder.begin() + in_end, preorder[pre_begin]);
            const int current_index = std::distance(inorder.begin(), inorder_current);

            head->left = recursive(preorder, inorder, pre_begin + 1, pre_begin + (current_index - in_begin), in_begin, current_index - 1);
            head->right = recursive(preorder, inorder, pre_begin + (current_index - in_begin) + 1, pre_end, current_index + 1, in_end);
        }
        
        return head;
    }
};

int main() {
    Solution solution;

    std::vector<int> pre_order{6, 2, 1, 4, 3, 5, 7, 9, 8};
    std::vector<int> in_order{1, 2, 3, 4, 5, 6, 7, 8, 9};
    TreeNode* answer = solution.buildTree(pre_order, in_order);

    return 0;
}

