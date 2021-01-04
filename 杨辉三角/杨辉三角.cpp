#include<stdio.h> 

int main()
{
    int i=0,j=0;
    char x='*';
	char arr[7][13]={0};
	for(i=0;i<=6;i++)
	{
		for(j=0;j<=i;j++)
		{
			arr[i][6-j]=x ;
		}
		printf("%c",arr[i][6-j]); 
	}printf("\n");
	return 0;
	
}
