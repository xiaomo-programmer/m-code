#include"stack.h"


int main()
{
	Stack s;
	StackInit(&s);
	StackPush(&s, 1);
	StackPush(&s, 2);
	StackPop(&s);
	StackPush(&s, 3);
	StackPush(&s, 4);
	

	while (!StackEmpty(&s))
	{
		printf(" %d ", Stacktop(&s));
		StackPop(&s);
	}
	
	system("pause");
	return 0;
}