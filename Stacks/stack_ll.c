#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct StackNode{
	int data;
	struct StackNode* next;
};

struct StackNode* newNode(int data){
	struct StackNode* node = (struct StackNode*)malloc(sizeof(struct StackNode));
	node -> data = data;
	node -> next = NULL;
	return node;
}
void push(struct StackNode** root, int value){
	struct StackNode* stacknode = newNode(value);
	stacknode->next = *root;
	*root = stacknode;
	printf("%d pushed into stack \n", value );	
}
int isEmpty(struct StackNode* root){
	return !root;
}
void pop(struct StackNode** root){
	if(isEmpty(*root)){
		printf("Stack is Empty \n");
		return;
	}
	struct StackNode* temp = *root;
	*root = (*root) -> next;
	printf("%d popped from stack \n", temp->data);
	free(temp); 
}
int main()
{
	struct StackNode* root = NULL;
	push(&root , 1);
	push(&root , 2);
	push(&root , 3);

	pop(&root);
	pop(&root);
	pop(&root);
	pop(&root);
	return 0;
}