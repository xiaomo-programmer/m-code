#include"Sort.h"

void printfArray(int* a,int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
}


void test1()
{
	int a[] = { 10, 4, 7, 8,  9, 5, 6, 2, 3 ,1};
	 //InsertSort(a, sizeof(a) / sizeof(int));
	//SelectSort(a, sizeof(a) / sizeof(int));
	//HeapSort(a, sizeof(a) / sizeof(int));
	//BubbleSort(a, sizeof(a) / sizeof(int));
	quicksort(a, 0, sizeof(a) / sizeof(int)-1);
	 printfArray(a, sizeof(a) / sizeof(int));
}


int main()
{
	test1();
	system("pause");
	return 0;
}