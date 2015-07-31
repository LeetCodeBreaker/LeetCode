/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
	//static int *buff = (int*)malloc(255*sizeof(int));
	static int buff[255];	
	static int iter=0;
	if(root==NULL){
		return NULL;
	}
	if(iter==0){
		*returnSize = 0;
		iter = 1;
	}
	inorderTraversal(root->left,returnSize);
	buff[*returnSize]=root->val;
	(*returnSize)++;
	inorderTraversal(root->right,returnSize);
    int bs=sizeof(int)*(*returnSize);
    int *res=malloc(bs);
    memcpy(res,buff,bs);

}
