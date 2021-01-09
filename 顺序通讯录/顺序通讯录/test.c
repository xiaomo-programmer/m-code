#define _CRT_SECURE_NO_WARNINGS

#include"addressList.h"

void menu()
{
	printf("1.初始化通讯录\n");
	printf("2.添加联系人\n");
	printf("3.查找联系人\n");
	printf("4.删除联系人\n");
	printf("5.联系人列表\n");
	printf("6.修改联系人\n");
	printf("0.退出\n");
}


void test()
{
	int i = 0;
	adList L;
	do
		
	{
		menu();
		printf("请输入：");
		scanf("%d",&i);
		switch (i)
		{
		case 1:
			adListInit(&L);
			break;
		case 2:
			adListadd(&L);
			break;
		case 3:
			adListFind(&L);
			break;
		case 4:
			adListDelete(&L);
			break;
		case 5:
			adListshow(&L);
			break;
		case 6:
			adListchange(&L);
			break;
		case 0:
			exit(-1);
			break;
		default:
			printf("请重新输入：");
				break;

		}
	} while (i);
}








int main()
{

	

	test();
	system("pause");
	return;
}