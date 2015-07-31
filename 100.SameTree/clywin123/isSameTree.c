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
