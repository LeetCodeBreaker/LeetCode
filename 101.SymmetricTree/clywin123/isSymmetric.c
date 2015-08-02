bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
	if(p==NULL || q ==NULL){
		if(p==NULL && q==NULL)	
			return true;
		else{
			return false;
		}
	}
	else if(p->val!=q->val){
		return false;
	}
	else
		return isSameTree(p->left,q->left)& isSameTree(p->right,q->right);
}

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

struct TreeNode* copy(struct TreeNode* root){
	struct TreeNode *node;
	if(root == NULL)
		return NULL;
	if(root){
		node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
		node->val = root->val;
		node->left= copy(root->left);
		node->right= copy(root->right);
	}
	return node;
}

bool isSymmetric(struct TreeNode* root) {
	struct TreeNode *tmp;
	tmp = copy(root);
	invertTree(root);
	return isSameTree(root,tmp);
}
