#define _CRT_SECURE_NO_WARNINGS

#include"addressList.h"

void menu()
{
	printf("1.��ʼ��ͨѶ¼\n");
	printf("2.�����ϵ��\n");
	printf("3.������ϵ��\n");
	printf("4.ɾ����ϵ��\n");
	printf("5.��ϵ���б�\n");
	printf("6.�޸���ϵ��\n");
	printf("0.�˳�\n");
}


void test()
{
	int i = 0;
	adList L;
	do
		
	{
		menu();
		printf("�����룺");
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
			printf("���������룺");
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