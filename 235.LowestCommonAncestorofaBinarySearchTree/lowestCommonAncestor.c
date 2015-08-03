struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
	struct TreeNode *le,*ri;
	if(root==NULL){
		return NULL;
	}
	else if((root->val == p->val)||(root->val == q->val))	    
		return root;
	else{
		le = lowestCommonAncestor(root->left,p,q);
		ri = lowestCommonAncestor(root->right,p,q);
		if(le != NULL && ri == NULL)
			return le;
		else if(ri !=NULL && le==NULL)
			return ri;
		else if(ri == NULL && le==NULL)
			return NULL;
		else
			return root;	
	}
}
