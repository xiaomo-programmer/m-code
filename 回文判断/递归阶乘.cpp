#include<stdio.h>
#include<stdlib.h>


int fun(int i)
{
	if(i<=1)
	return 1;
	return (i*fun(i-1));	
}


int main()
{
	int a,b;
	printf("������һ������\n");
	scanf("%d",&a);
	b=fun(a);
	printf("%d�Ľ׳�Ϊ%d\n",a,b);
	system("pause");
	return 0;
}
