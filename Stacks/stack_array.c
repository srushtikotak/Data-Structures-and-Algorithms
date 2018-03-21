#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct Stack{
	int top;
	unsigned capacity;
	int* array;
};

struct Stack* createstack(unsigned capacity){
	struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
	stack-> capacity = capacity;
	stack-> top = -1;
	stack->array = (int*)malloc(stack->capacity * sizeof(int));
	return stack;
}

int isFull(struct Stack* stack){
	return stack->top == stack->capacity-1;
}
int isEmpty(struct Stack* stack){
	return stack->top == -1;
}
void push(struct Stack* stack, int value){
	if(isFull(stack))
		return;
	stack->array[++stack->top] = value;
	printf("%d pushed into stack\n",value);
}
int pop(struct Stack* stack){
	if(isEmpty(stack))
		return INT_MIN;
	return stack->array[stack->top--];
}

int main(){
	struct Stack* stack = createstack(100);

	push(stack, 1);
	push(stack, 2);
	push(stack, 3);

	printf("%d popped from the stack \n", pop(stack));
	printf("%d popped from the stack \n", pop(stack));
	printf("%d popped from the stack \n", pop(stack));
}