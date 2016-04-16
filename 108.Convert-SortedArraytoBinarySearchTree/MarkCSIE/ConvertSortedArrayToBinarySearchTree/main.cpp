#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
    }
};

class Solution {
public:

    TreeNode* sortedArrayToBST(const std::vector<int>& nums) {
        int length = nums.size();
        if (length == 0) {
            return nullptr;
        }

        int mid_index = length / 2;
        TreeNode* root = new TreeNode(nums[mid_index]);

        TreeNode* left_root = nullptr;
        int leftSize = mid_index;
        if (leftSize > 0) {
            std::vector<int> leftNum(nums.begin(), nums.begin() + mid_index);
            left_root = sortedArrayToBST(leftNum);
        }

        TreeNode* right_root = nullptr;
        int rightSize = length - (mid_index + 1);
        if (rightSize > 0) {
            std::vector<int> rightNum(nums.begin() + mid_index + 1, nums.end());
            right_root = sortedArrayToBST(rightNum);
        }

        root->left = left_root;
        root->right = right_root;

        return root;
    }
};

int main() {
    Solution solution;

    std::vector<int> test{1, 2, 3, 4, 5};
    TreeNode* answer = solution.sortedArrayToBST(test);

    return 0;
}

