struct TreeNode* invertTree(struct TreeNode* root) {
	struct TreeNode *tmp;
	if(root){
		tmp = root -> left;
		root -> left = root -> right;
		root -> right = tmp;
		invertTree(root->left);
		invertTree(root->right);
	}
	return root;
}
