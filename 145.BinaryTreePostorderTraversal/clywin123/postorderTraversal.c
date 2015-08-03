int* postorderTraversal(struct TreeNode* root, int* returnSize) {
	//static int *buff = (int*)malloc(255*sizeof(int));
	static int buff[255]={0};	
	static int iter=0;
	if(root==NULL){
		return ;
	}
	if(iter==0){
		*returnSize = 0;
		iter = 1;
	}
	postorderTraversal(root->left,returnSize);
	postorderTraversal(root->right,returnSize);
	buff[*returnSize]=root->val;
	(*returnSize)++;
	int bs=sizeof(int)*(*returnSize);
	int *res=malloc(bs);
	memcpy(res,buff,bs);
	return res;
}
