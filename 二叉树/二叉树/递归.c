#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	char data;
	struct node*LChild;
	struct node*RChild;
}node, *bitree;

//初始化
int initbitree(bitree *L)
{
	*L = (bitree)malloc(sizeof(node));
	(*L)->LChild = NULL;
	(*L)->RChild = NULL;
	return 0;
}

//先序创建二叉链表
void creatbitree(bitree *L)
{
	char ch;
    ch = getchar();
	if (ch == '*') *L = NULL;   
	else
	{
		*L = (bitree)malloc(sizeof(node));
		(*L)->data = ch;
		creatbitree(&((*L)->LChild));
		creatbitree(&((*L)->RChild));
	}
}

//先序遍历
void preorder(bitree L)
{
	if (L != NULL)
	{
		printf("%c", L->data);
		preorder(L->LChild);
		preorder(L->RChild);
	}
}

//中序遍历
void inorder(bitree L)
{
	if (L != NULL)
	{
		inorder(L->LChild);
		printf("%c", L->data);
		inorder(L->RChild);
	}
}

//后序遍历
void postorder(bitree L)
{
	if (L != NULL)
	{
		postorder(L->LChild);
		postorder(L->RChild);
		printf("%c", L->data);
	}
}

int main()
{
	bitree L;
	initbitree(&L);
	printf("先序输入二叉树：");
	creatbitree(&L);
	printf("\n");
	printf("先序序列为：");
	preorder(L);
	printf("\n");
	printf("中序序列为：");
	inorder(L);
	printf("\n");
	printf("后序序列为：");
	postorder(L);
	printf("\n");
}


