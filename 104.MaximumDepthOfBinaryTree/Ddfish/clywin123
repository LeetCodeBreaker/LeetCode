int max(int a,int b){
	if(a>b)
		return a;
	return b;
}
int maxDepth(struct TreeNode* root) {
	if(root==NULL){	   
		return 0;
	}
	else
		return 1+max(maxDepth(root->left),maxDepth(root->right));
}
