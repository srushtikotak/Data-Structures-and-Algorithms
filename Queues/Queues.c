#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct Queue{
	int front, rear, size;
	unsigned capacity;
	int* array;
};
struct Queue* createQueue(unsigned capacity){
	struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
	queue -> size = queue -> front = 0;
	queue -> rear = capacity-1;
	queue -> capacity = capacity;
	queue -> array = (int*)malloc(queue->capacity * sizeof(int));
	return queue;
}
int isFull(struct Queue* queue){
	return (queue->size == queue->capacity);
}
int isEmpty(struct Queue* queue){
	return(queue->size == 0);
}
void enqueue(struct Queue* queue, int value){
	if(isFull(queue))
		return;
	queue -> rear = (queue->rear+1)%queue->capacity;
	queue->array[queue -> rear] = value;
	queue -> size = queue->size+1;
	printf("%d added to queue \n", value);
}
void dequeue(struct Queue* queue){
	if(isEmpty(queue))
		return;
	int value = queue->array[queue->front];
	queue->front = (queue->front+1)%queue->capacity;
	queue->size = queue->size-1;
	printf("%d removed from queue \n", value);
}
int main(){
	struct Queue* queue = createQueue(10);
	
	enqueue(queue , 1);
	enqueue(queue , 2);
	enqueue(queue , 3);

	dequeue(queue);
	dequeue(queue);
	dequeue(queue);
	
	return 0;
}