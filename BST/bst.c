#include <stdio.h>
#include <stdlib.h>

struct node{
	int key;
	struct node *left,*right;
};

struct node* createnode(int value){
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->key = value;
	temp->left = temp->right = NULL;
	return temp;
}
struct node* insert(struct node* node, int value){
	if(node == NULL)
		return createnode(value);
	if(value < node->key)
		node->left = insert(node->left, value);
	else if(value > node->key)
		node->right = insert(node->right, value);
	return node;
}
void inorder(struct node* node){
	if(node != NULL){
		inorder(node->left);
		printf("%d  \n",node->key);
		inorder(node->right);
	}
}
int main(void) {
	struct node *root=NULL;
	root = insert(root, 100);
	insert(root, 90);
	insert(root, 110);
	insert(root, 80);
	insert(root, 95);

	inorder(root);
	return 0;
}


