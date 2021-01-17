bool isSameTree(struct TreeNode* p, struct TreeNode* q){
	if (p == NULL && q == NULL)
		return true;
	//结构不相同
	if (p == NULL && q != NULL)
		return false;
	if (p != NULL && q == NULL)
		return false;
	//值不同
	if (p->val != q->val)
		return false;
	return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}


bool isSubtree(struct TreeNode* s, struct TreeNode* t){
	if (s == NULL)
		return false;


	if (isSameTree(s, t))
		return true;

	return isSubtree(s->left, t) || isSubtree(s->right, t);

}