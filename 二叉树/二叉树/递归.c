#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	char data;
	struct node*LChild;
	struct node*RChild;
}node, *bitree;

//��ʼ��
int initbitree(bitree *L)
{
	*L = (bitree)malloc(sizeof(node));
	(*L)->LChild = NULL;
	(*L)->RChild = NULL;
	return 0;
}

//���򴴽���������
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

//�������
void preorder(bitree L)
{
	if (L != NULL)
	{
		printf("%c", L->data);
		preorder(L->LChild);
		preorder(L->RChild);
	}
}

//�������
void inorder(bitree L)
{
	if (L != NULL)
	{
		inorder(L->LChild);
		printf("%c", L->data);
		inorder(L->RChild);
	}
}

//�������
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
	printf("���������������");
	creatbitree(&L);
	printf("\n");
	printf("��������Ϊ��");
	preorder(L);
	printf("\n");
	printf("��������Ϊ��");
	inorder(L);
	printf("\n");
	printf("��������Ϊ��");
	postorder(L);
	printf("\n");
}


