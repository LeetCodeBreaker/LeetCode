
//  Definition for a binary tree node.

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(const int &x) : val(x), left(nullptr), right(nullptr) {
    }
};

class Solution {
public:

    TreeNode* invertTree(TreeNode * const root) {
        if (root) {
            TreeNode* temp = root->left;
            root->left = root->right;
            root->right = temp;
            invertTree(root->left);
            invertTree(root->right);
        }

        return root;
    }
};

int main() {
    TreeNode* test = new TreeNode(4);
    test->left = new TreeNode(2);
    test->right = new TreeNode(7);
    test->left->left = new TreeNode(1);
    test->left->right = new TreeNode(3);
    test->right->left = new TreeNode(6);
    test->right->right = new TreeNode(9);

    delete test->right->right;
    delete test->right->left;
    delete test->left->right;
    delete test->left->left;
    delete test->right;
    delete test->left;
    delete test;

    return 0;
}

