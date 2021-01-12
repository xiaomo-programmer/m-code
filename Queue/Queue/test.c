#include"Queue.h"

void Test()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);

	QueuePush(&q, 4);

	while (!(QueueEmpty(&q)))
	{
		printf("%d ", QueueFront(&q));
		QueuePop(&q);
	}
	QueueDestroy(&q);
}


int main()
{
	Test();
	system("pause");
	return 0;
}