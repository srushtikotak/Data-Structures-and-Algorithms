#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node *next;
};

void push(struct Node** head_ref, int new_data){
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node*));
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

void insertAfter(struct Node* prev , int new_data){
	if(prev->next == NULL){
		printf("the given previous node cannot be NULL");
      	return;
	}
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node*));
	new_node -> data = new_data;
	new_node -> next = prev->next;
	prev->next = new_node;
}

void append(struct Node** head_ref,int new_data){
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node*));
	new_node-> data = new_data;
	new_node-> next = NULL;

	struct Node *last = *head_ref;
	if(*head_ref == NULL){
		*head_ref=new_node;
		return;
	}
	while(last->next != NULL)
		last = last->next;
	last->next = new_node;
}

void deletenode(struct Node** head_ref , int key){
	struct Node* temp = *head_ref, *prev;
	if(temp != NULL && temp->data == key){
		*head_ref = temp->next;
		free(temp);
		return;
	}
	while(temp != NULL && temp->data != key){
		prev = temp;
		temp = temp->next;
	}
	if(temp == NULL) return;

	prev->next = temp->next;
	printf("Node Deleted : %d \n", temp->data);
	free(temp);
	return;
}
void printlist(struct Node *a){
	while(a != NULL){
		printf("%d \n", a->data);
		a = a-> next;
	}

}
int main(){
	struct Node *head = NULL;
	struct Node *second = NULL;
	struct Node *third = NULL;

	head = (struct Node*)malloc(sizeof(struct Node));
	second = (struct Node*)malloc(sizeof(struct Node));
	third = (struct Node*)malloc(sizeof(struct Node));

	head->data = 1;
	head->next = second;

	second->data = 2;
	second->next = third;

	third->data = 3;
	third->next = NULL;
    
    push(&head , 10);
    insertAfter(head->next, 8);
    append(&head, 9);
    printlist(head);
    deletenode(&head , 2);
    printlist(head);
	return 0;
}
