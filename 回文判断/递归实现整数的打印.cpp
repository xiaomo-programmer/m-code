#include<stdio.h>

#include<stdlib.h> 

void prism(int n)
{
	if(n>9)
	{
		prism(n/10);
		
	}
	printf("%d\n",n%10);
}









int main()
{   int i=1234;
	prism(i);
	system("pause");
	return 0;
}
