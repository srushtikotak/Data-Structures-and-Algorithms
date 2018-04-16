#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct node{
	int data;
	int priority;
	struct node* next;
}Node;

Node* newNode(int data, int priority){
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = data;
	temp->priority = priority;
	temp->next = NULL;
}
void push(Node** head, int data, int priority){
	Node* start = *head;
	Node* temp = newNode(data, priority);

	if(((*head)->priority) > priority){
		temp->next = (*head);
		(*head) = temp;
	}
	else{
		while(start->next != NULL && start->next->priority < priority)
			start = start->next;
		temp->next = start->next;
		start->next = temp;
	}
}
void pop(Node **head){
	Node* temp = *head;
	(*head) = (*head)->next;
	printf("Popped item : %d, priority : %d \n", temp->data , temp->priority );
	free(temp);
}
void print(Node** head){
	Node* start = *head;
	printf("Items in the priority queue are : \n");
	while(start->next != NULL){
		printf("Value : %d, Priority : %d\n", start->data, start->priority );
		start = start->next;
	}
	printf("Value : %d, Priority : %d\n", start->data, start->priority );
}
int main()
{
	Node *pq = newNode(10, 1);
	push(&pq ,20, 2);
	push(&pq ,40, 4);
	push(&pq ,30, 3);
	print(&pq);	
	pop(&pq);
	print(&pq);
	return 0;
}