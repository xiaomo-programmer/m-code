

#include"Queue.h"





// 初始化队列 
void QueueInit(Queue* q)
{
	assert(q);
	q->front = q->rear = NULL;
}

// 队尾入队列 
void QueuePush(Queue* q, QDataType data)
{
	assert(q);
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		printf("内存不足\n");
		exit(-1);

	}
	newnode->data = data;
	newnode->next = NULL;
	if (q->front == NULL)
	{
		q->front = q->rear = newnode;
	}
	else
	{
		q->rear->next = newnode;
		q->rear = newnode;
	}

}

// 队头出队列 
void QueuePop(Queue* q)
{
	assert(q);
	QNode* next = q->front->next;
	free(q->front);
	q->front = next;

	if (q->front == NULL)
	{
		q->rear = NULL;
	}
}
// 获取队列头部元素 
QDataType QueueFront(Queue* q)
{
	assert(q);
	assert(q->front);
	return q->front->data;
}
// 获取队列队尾元素 
QDataType QueueBack(Queue* q)
{
	assert(q);
	assert(q->rear);
	return q->rear->data;

}
// 获取队列中有效元素个数 
int QueueSize(Queue* q)
{
	assert(q);
	QNode* cur = q->front;
	int size = 0;
	while (cur)
	{
		cur = cur->next;
		size++;
	}
	return size;
}
// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* q)
{
	assert(q);
	
	return q->front == NULL ? 1 : 0;
}
// 销毁队列 
void QueueDestroy(Queue* q)
{
	QNode* cur = q->front;
	while (cur)
	{
		QNode* next = cur->next;
		free(cur);

		cur = next;
	}
	q->front = q->rear = NULL;
}