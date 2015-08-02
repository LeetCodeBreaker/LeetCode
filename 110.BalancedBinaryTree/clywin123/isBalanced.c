int max(int a,int b){
	if(a>b)
		return a;
	return b;
}
int height(struct TreeNode* root){
	if(root ==NULL)
		return 0;
	else
		return 1+max(height(root->left),height(root->right));
}

bool isBalanced(struct TreeNode* root) {
	int lv,rv,diff;
	if(root==NULL)
		return true;
	else{
		lv = height(root->left);
		rv = height(root->right);
		diff = lv-rv;
		if(diff<0)
			diff *= (-1);
		if(diff<=1){
			return isBalanced(root->left)&isBalanced(root->right);
		}
		else
			return false;
	}
}
