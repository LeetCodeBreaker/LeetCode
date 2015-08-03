int* preorderTraversal(struct TreeNode* root, int* returnSize) {
	static int buff[255];	
	static int iter=0;
	if(root==NULL){
		return NULL;
	}
	if(iter==0){
		*returnSize = 0;
		iter = 1;
	}
	buff[*returnSize]=root->val;
	(*returnSize)++;
	preorderTraversal(root->left,returnSize);
	preorderTraversal(root->right,returnSize);
	int bs=sizeof(int)*(*returnSize);
    int *res=malloc(bs);
    memcpy(res,buff,bs);
    return res;

}
