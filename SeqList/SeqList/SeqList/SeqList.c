
#include"SeqList.h"


void SeqListInit(SeqList* L)//初始化
{

	//初始化1
	/*S.a = 0;
	S.size = NULL;
	S.capacity = 0;*/

	L->a = (ElementData*)malloc(sizeof(ElementData)* 4);
	if (L->a == NULL)
	{
		printf("申请内存空间失败！");
		exit(-1);
	}
	L->capacity = 4;
	L->size = 0;
}

void SeqListPrint(SeqList* L)//输出
{
	assert(L);
	//越界增容  通常情况增加二倍 

	for (int i = 0; i < L->size; i++)
	{
		printf("%d ", L->a[i]);
	}
	printf("\n");
}




//尾插尾删

void SeqListPushBack(SeqList* L, ElementData x)
{
	assert(L);
	if (L->size >= L->capacity)
	{
		L->capacity *= 2;
		L->a = (ElementData*)realloc(L->a, sizeof(ElementData)*L->capacity);
		if (L->a == NULL)
		{
			printf("增容失败！");
			exit(-1);
		}
	}

	L->a[L->size] = x;
	L->size++;
}
void SeqListPopBack(SeqList* L)
{
	assert(L);

	L->size--;
}



//扩容空间
void SeqListCheckCapacity(SeqList* L)
{
	if (L->size >= L->capacity)
	{
		L->capacity *= 2;
		L->a = (ElementData*)realloc(L->a, sizeof(ElementData)*L->capacity);
		if (L->a == NULL)
		{
			printf("增容失败！");
			exit(-1);
		}
	}
}
//头插头删
void SeqListPushFront(SeqList* L, ElementData x)
{
	assert(L);
	SeqListCheckCapacity(L);
	int end = L->size - 1;
	while (end >= 0)
	{
		L->a[end + 1] = L->a[end];
		end--;
	}
	L->a[0] = x;
	L->size++;
}
void SeqListPopFront(SeqList* L)
{

	for (int i = 1; i < L->size; i++)
	{
		L->a[i - 1] = L->a[i];

	}
	L->size--;
}
//中间插入
void SeqListInsert(SeqList* L, int pos, ElementData x)
{
	assert(L);
	assert(pos<L->size);
	int end = L->size;
	if (pos > 0 && pos < L->size - 1)
	{
		while (end >pos)
		{
			L->a[end] = L->a[end - 1];
			end--;
		}
		L->a[pos] = x;
		L->size++;
	}
	else
		return false;
}
//中间删除
void SeqListErase(SeqList* L, int pos)
{
	assert(L);
	assert(pos<L->size - 1 && pos>0);
	int start = pos + 1;
	while (start < L->size)
	{
		L->a[start - 1] = L->a[start];
		start++;
	}
	L->size--;
}

//查找
int SeqListsearch(SeqList*L, ElementData x)
{
	assert(L);
	int i = 0;
	while (i < L->size)
	{
		if (L->a[i] == x)
		{
			return i;
		}
		i++;
	}
	return -1;
}
//删除
int SeqListDestory(SeqList*L, ElementData x)
{
	int pos = SeqListsearch(L, x);
	int start = pos;
	if (pos != -1)
	{
		while (start < L->size - 1)
		{
			L->a[start] = L->a[start+1];
			start++;
		}
	}
	L->size--;
}


