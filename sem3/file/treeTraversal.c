#include <stdio.h>
#include <stdlib.h>

typedef struct node_t {
	int data;
	struct node_t* left;
	struct node_t* right;
} node_t;

node_t* create_node(int data){
	node_t* node = malloc(sizeof(node_t));
	node->data = data;
	node->left = node->right = NULL;
	return node;
}

void pre_order_traversal(node_t* root){
	if (root == NULL)return;
	printf("%d ", root->data);
	pre_order_traversal(root->left);
	pre_order_traversal(root->right);
}

void in_order_traversal(node_t* root){
	if (root == NULL)return;
	in_order_traversal(root->left);
	printf("%d ", root->data);
	in_order_traversal(root->right);
}

void post_order_traversal(node_t* root){
	if (root == NULL)return;
	post_order_traversal(root->left);
	post_order_traversal(root->right);
	printf("%d ", root->data);
}

int main(void){
	node_t* root = create_node(1);
	root->left = create_node(2);
	root->right = create_node(3);
	root->left->left = create_node(4);
	root->left->right = create_node(5);

	printf("Pre-order traversal: ");
	pre_order_traversal(root);
	printf("\n");

	printf("In-order traversal: ");
	in_order_traversal(root);
	printf("\n");

	printf("Post-order traversal: ");
	post_order_traversal(root);
	printf("\n");

	return 0;
}
