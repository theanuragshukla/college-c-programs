#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *left;
  struct node *right;
};

struct node* createNode(int data) {
  struct node *newNode = (struct node*)malloc(sizeof(struct node));
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

struct node* insert(struct node* root, int data) {
  if (root == NULL) return createNode(data);
  if (data < root->data) root->left  = insert(root->left, data);
  else if (data > root->data) root->right = insert(root->right, data);
  return root;
}

struct node* minValueNode(struct node* node) {
  struct node* current = node;
  while (current->left != NULL) current = current->left;
  return current;
}


struct node* deleteNode(struct node* root, int data) {
  if (root == NULL) return root;
  if (data < root->data) root->left = deleteNode(root->left, data);
  else if (data > root->data) root->right = deleteNode(root->right, data);
  else {
	if (root->left == NULL) {
  	struct node *temp = root->right;
  	free(root);
  	return temp;
	}
	else if (root->right == NULL) {
  	struct node *temp = root->left;
  	free(root);
  	return temp;
	}
	struct node* temp = minValueNode(root->right);
	root->data = temp->data;
	root->right = deleteNode(root->right, temp->data);
  }
  return root;
}
int main() {
  struct node* root = NULL;
  int choice, data;
  while (1) {
	printf("1. Insert\n2. Delete\n3. Quit\nEnter your choice: ");
	scanf("%d", &choice);
	if (choice == 3) break;
	printf("Enter an integer: ");
	scanf("%d", &data);
	root = (choice == 1) ? insert(root, data) : deleteNode(root, data);
  }
  return 0;
}
