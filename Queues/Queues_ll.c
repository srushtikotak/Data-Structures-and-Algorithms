#include<stdio.h>
#include<stdlib.h>
struct Qnode
{
	int key;
	struct Qnode *next;
};
struct Queue
{
	struct Qnode *front,*rear;
};
struct Qnode *createNode(int key)
{
	struct Qnode *qn = (struct Qnode*)malloc(sizeof(struct Qnode));
	qn -> key = key;
	qn -> next = NULL;
	return qn;
};
struct Queue *createQueue()
{
	struct Queue *q = (struct Queue*)malloc(sizeof(struct Queue));
	q->front = q->rear = NULL;
	return q;
};
void Enqueue(struct Queue* q, int key){
	struct Qnode *qn = createNode(key);
	printf("Enqueued item is %d \n", qn->key);
	if (q->rear == NULL)
	{
		q->front = q->rear = qn;
		return;
	}
	q->rear->next = qn;
	q->rear = qn;
}
void Dequeue(struct Queue *q){
	if(q->front == NULL)
		return;
	struct Qnode *temp = q->front;
	q->front = q->front->next;

	printf("Dequeued item is %d \n", temp->key);

	if(q->front == NULL)
		q->rear = NULL;
}
int main()
{
	struct Queue *q = createQueue();
	Enqueue(q,50);
	Enqueue(q,80);
	Enqueue(q,110);
	Enqueue(q,140);

	Dequeue(q);
	Dequeue(q);
	Dequeue(q);
	Dequeue(q);

	return 0;
}