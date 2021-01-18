//单值二叉树
bool isUnivalTree(struct TreeNode* root)
{
	if (root == NULL)
	{
		return true;
	}
	if (root->left && root->val != root->left->val)
	{
		return false;
	}
	if (root->right && root->val != root->right->val)
	{
		return false;
	}
	return isUnivalTree(root->left) && isUnivalTree(root->right);


}

//二叉树的深度
int maxDepth(struct TreeNode* root){
	int h1, h2, max;
	if (root != NULL)
	{
		h1 = maxDepth(root->left);
		h2 = maxDepth(root->right);
		max = h1>h2 ? h1 : h2;
		return (max + 1);
	}
	else
		return 0;
}

//翻转二叉树
typedef struct TreeNode TNode;
struct TreeNode* invertTree(struct TreeNode* root){
	if (root == NULL)
	{
		return NULL;
	}
	else
	{
		TNode* temp = root->left;
		root->left = root->right;
		root->right = temp;
		invertTree(root->left);
		invertTree(root->right);

	}
	return root;
}


//检查两棵树是否相同
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


//对称二叉树
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



//另一棵树的子树
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

//判断一棵树是否为平衡树
int TreeDepth(struct TreeNode* root)
{
	if (root == NULL)
		return 0;
	int leftDepth = TreeDepth(root->left);
	int rightDepth = TreeDepth(root->right);
	return leftDepth >rightDepth ? leftDepth + 1 : rightDepth + 1;
}

bool isBalanced(struct TreeNode* root){
	if (root == NULL)
		return true;
	int tmp = abs(TreeDepth(root->left) - TreeDepth(root->right));

	if (tmp > 1)
		return false;

	return isBalanced(root->left) && isBalanced(root->right);

}


//二叉树的构建和遍历
#include<stdio.h>
#include<malloc.h>

typedef struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
}TreeNode;


TreeNode* creatTree(char* str, int *p)
{
	if (str[*p] == '#')
	{
		(*p)++;
		return NULL;
	}
	else
	{
		TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
		root->val = str[*p];
		(*p)++;
		root->left = creatTree(str, p);
		root->right = creatTree(str, p);
		return root;
	}
}

void Inorder(TreeNode* root)
{
	if (root == NULL)
		return;
	Inorder(root->left);
	printf("%c ", root->val);
	Inorder(root->right);
}

int main()
{
	char str[1000];
	scanf("%s", str);
	int i = 0;
	TreeNode* root = creatTree(str, &i);
	Inorder(root);
	return 0;
}


//二叉树的前序遍历
int TreeSize(struct TreeNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return 1 + TreeSize(root->left) + TreeSize(root->right);
}

void _preorderTraversal(struct TreeNode* root, int* arry, int* pi)
{
	if (root == NULL)
	{
		return;

	}
	arry[(*pi)++] = root->val;
	_preorderTraversal(root->left, arry, pi);
	_preorderTraversal(root->right, arry, pi);

}





int* preorderTraversal(struct TreeNode* root, int* returnSize){
	int size = TreeSize(root);
	int* array = (int*)malloc(sizeof(int)*size);

	int i = 0;
	_preorderTraversal(root, array, &i);

	*returnSize = size;
	return array;
}



//二叉树的中序遍历

int TreeSize(struct TreeNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return 1 + TreeSize(root->left) + TreeSize(root->right);
}

void _inorderTraversal(struct TreeNode* root, int* arry, int* pi)
{
	if (root == NULL)
	{
		return;

	}
	_inorderTraversal(root->left, arry, pi);
	arry[(*pi)++] = root->val;
	_inorderTraversal(root->right, arry, pi);

}





int* inorderTraversal(struct TreeNode* root, int* returnSize){
	int size = TreeSize(root);
	int* array = (int*)malloc(sizeof(int)*size);

	int i = 0;
	_inorderTraversal(root, array, &i);

	*returnSize = size;
	return array;
}


//二叉树的后序遍历
int TreeSize(struct TreeNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return 1 + TreeSize(root->left) + TreeSize(root->right);
}

void _postorderTraversal(struct TreeNode* root, int* arry, int* pi)
{
	if (root == NULL)
	{
		return;

	}
	_postorderTraversal(root->left, arry, pi);
	_postorderTraversal(root->right, arry, pi);
	arry[(*pi)++] = root->val;
}





int* postorderTraversal(struct TreeNode* root, int* returnSize){
	int size = TreeSize(root);
	int* array = (int*)malloc(sizeof(int)*size);

	int i = 0;
	_postorderTraversal(root, array, &i);

	*returnSize = size;
	return array;
}