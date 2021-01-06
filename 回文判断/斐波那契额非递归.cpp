#include<stdio.h>
#include<stdlib.h>
int fib(int n)
{
	int n1=1;int n2=1;
	int ret=1;
	if(n<=2)
	return 1;
	else
	{
		int i=3;
		for(i=3;i<=n;i++)
		{
			ret=n1+n2;
			n1=n2;
			n2=ret;
			
		}
		return ret;
	}
}
int main()
{
	int i=0;
	printf("请输入一个数：\n");
	scanf("%d",&i);
	printf("%d\n",fib(i));
	system("pause");
	return 0;
}
