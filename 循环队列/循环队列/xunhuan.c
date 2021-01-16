typedef struct {

	int*  _a;
	int front;
	int rear;
	int _k;
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {
	MyCircularQueue* q = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
	q->_a = malloc(sizeof(int)*(k + 1));
	q->front = 0;
	q->rear = 0;
	q->_k = k;
	return q;
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj);
bool myCircularQueueIsFull(MyCircularQueue* obj);


bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
	if (myCircularQueueIsFull(obj))
		return false;
	else
	{
		obj->_a[obj->rear] = value;
		obj->rear++;
		obj->rear = obj->rear % (obj->_k + 1);
		return true;
	}
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
	if (myCircularQueueIsEmpty(obj))
	{
		return false;

	}
	obj->front++;
	obj->front = obj->front % (obj->_k + 1);
	return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
	if (myCircularQueueIsEmpty(obj))
		return -1;
	else
		return obj->_a[obj->front];
}

int myCircularQueueRear(MyCircularQueue* obj) {
	if (myCircularQueueIsEmpty(obj))
		return -1;
	else
	{
		int tail = obj->rear - 1;
		if (tail == -1)
			tail = obj->_k;
		return obj->_a[tail];
	}
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
	return obj->front == obj->rear;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
	return (obj->rear + 1) % (obj->_k + 1) == obj->front;
}

void myCircularQueueFree(MyCircularQueue* obj) {
	free(obj->_a);
	free(obj);
}
