int _isSymmetric(struct TreeNode*p, struct TreeNode* q)
{
	if (p == NULL && q == NULL)
	{
		return true;
	}
	if (p == NULL || q == NULL)
	{
		return false;
	}
	return (p->val == q->val) &&
		_isSymmetric(p->left, q->right) &&
		_isSymmetric(p->right, q->left);
}







bool isSymmetric(struct TreeNode* root){
	if (root == NULL)
		return true;
	return _isSymmetric(root->left, root->right);

}