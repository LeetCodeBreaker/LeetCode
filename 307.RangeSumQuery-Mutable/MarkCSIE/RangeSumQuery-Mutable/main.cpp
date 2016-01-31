#include <iostream>
#include <vector>

// Definition for a binary tree node.

struct SumTreeNode {
    int sum;
    int begin;
    int end;

    SumTreeNode *left;
    SumTreeNode *right;

    SumTreeNode(int sum, int begin, int end) : sum(sum), begin(begin), end(end), left(nullptr), right(nullptr) {
    }

    ~SumTreeNode() {
        if (left) {
            delete left;
        }
        left = nullptr;

        if (right) {
            delete right;
        }
        right = nullptr;
    }
};

class NumArray {
public:
    SumTreeNode* tree;

    SumTreeNode* buildTree(const int &begin, const int &end, const std::vector<int> &nums) {
        SumTreeNode* head = new SumTreeNode(nums[begin], begin, end);
        if (begin == end) {
            return head;
        }

        int mid = (begin + end) / 2;
        head->left = buildTree(begin, mid, nums);
        head->right = buildTree(mid + 1, end, nums);
        head->sum = head->left->sum + head->right->sum;

        return head;
    }

    NumArray(const std::vector<int> &nums) : tree(nullptr) {
        if (nums.size() > 0) {
            tree = buildTree(0, nums.size() - 1, nums);
        }
    }

    ~NumArray() {
        if (tree) {
            delete tree;
        }
        tree = nullptr;
    }

    void updateTreeRangeVal(SumTreeNode* head, const int &i, const int &val) {
        if (i != head->begin || i != head->end) {
            int mid = (head->begin + head->end) / 2;
            if (i <= mid) {
                updateTreeRangeVal(head->left, i, val);
            } else {
                updateTreeRangeVal(head->right, i, val);
            }
            head->sum = head->left->sum + head->right->sum;
        } else {
            head->sum = val;
        }
    }

    void update(const int &i, const int &val) {
        if (!tree) {
            return;
        }
        updateTreeRangeVal(tree, i, val);
    }

    int getTreeRangeVal(const SumTreeNode* head, const int &begin, const int &end) {
        int mid = (head->begin + head->end) / 2;

        if (begin == head->begin && end == head->end) {
            return head->sum;
        } else if (end <= mid) {
            return getTreeRangeVal(head->left, begin, end);
        } else if (begin > mid) {
            return getTreeRangeVal(head->right, begin, end);
        } else {
            return getTreeRangeVal(head->left, begin, head->left->end) + getTreeRangeVal(head->right, head->right->begin, end);
        }
    }

    int sumRange(const int &i, const int &j) {
        if (!tree) {
            return 0;
        }
        return getTreeRangeVal(tree, i, j);
    }
};

int main() {
    std::vector<int> nums{1, 3, 5};
    NumArray numArray(nums);
    std::cout << numArray.sumRange(0, 2) << std::endl;
    numArray.update(1, 2);
    std::cout << numArray.sumRange(0, 2) << std::endl;
    return 0;
}

