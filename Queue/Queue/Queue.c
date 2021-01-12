

#include"Queue.h"





// ��ʼ������ 
void QueueInit(Queue* q)
{
	assert(q);
	q->front = q->rear = NULL;
}

// ��β����� 
void QueuePush(Queue* q, QDataType data)
{
	assert(q);
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		printf("�ڴ治��\n");
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

// ��ͷ������ 
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
// ��ȡ����ͷ��Ԫ�� 
QDataType QueueFront(Queue* q)
{
	assert(q);
	assert(q->front);
	return q->front->data;
}
// ��ȡ���ж�βԪ�� 
QDataType QueueBack(Queue* q)
{
	assert(q);
	assert(q->rear);
	return q->rear->data;

}
// ��ȡ��������ЧԪ�ظ��� 
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
// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
int QueueEmpty(Queue* q)
{
	assert(q);
	
	return q->front == NULL ? 1 : 0;
}
// ���ٶ��� 
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