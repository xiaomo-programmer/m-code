#include<stdio.h>
#include<stdlib.h>


int fun(int n,int k)
{
	if(k==0)
	return 1;
	return n*fun(n,k-1);
	
}
int main()
{
	int n=2;
	int k=4;
	int A=fun(2,4);
	printf("%d\n",A);
	system("pause");
	return 0;
}
