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
		printf("%d  ",node->key);
		inorder(node->right);
	}
}
struct node* MinValue(struct node* node){
	while(node->left != NULL)
		node = node->left;
	return node;
};
struct node* delete(struct node* root, int value){
	if(root == NULL)
		return root;
	if(value < root->key)
		root->left = delete(root->left, value);
	else if(value > root->key)
		root->right = delete(root->right, value);
	else{
		if(root->left == NULL){
			struct node *temp = root->right;
			free(root);
			return temp;
		}
		else if(root->right == NULL){
			struct node *temp = root->left;
			free(root);
			return temp;
		}
		struct node *temp = MinValue(root->right);
		root->key = temp->key;
		root->right = delete(root->right, temp->key);
	}
	printf("Deleted node is %d\n", value );
	return root;
};
int main(void) {
	struct node *root=NULL;
	root = insert(root, 100);
	insert(root, 90);
	insert(root, 110);
	insert(root, 80);
	insert(root, 95);

	inorder(root);
	printf("\n");

	delete(root,100);

	inorder(root);
	printf("\n");

	return 0;
}


