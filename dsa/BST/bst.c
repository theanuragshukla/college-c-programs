#include <stdio.h>
#include <stdlib.h>
typedef struct Node node;
struct Node{
	node * left;
	node *right;
	int data;
};

void add(node* root, int data);
void preorderTraverse(node* root);
void inorderTraverse(node* root);
void postorderTraverse(node* root);

int main(){
	node * root = (node*)malloc(sizeof(node));
	root->left=NULL;
	root->right=NULL;
	root->data=10;
	add(root, 1);
	add(root, 2);
	add(root, 3);
	add(root, 4);
	add(root, 5);
	add(root, 6);
	add(root, 7);
	add(root, 8);
	add(root, 9);
	add(root, 10);
	add(root, 165);
	add(root, 157);
	add(root, 87);
	add(root, 756);
	add(root, 89875);
	add(root, 46);
	add(root, 99);
	printf("\n");
	preorderTraverse(root);
	printf("\n");
	inorderTraverse(root);
	printf("\n");
	postorderTraverse(root);
	return 0;
}
void preorderTraverse(node* root){
	if(root==NULL){
		return;
	}
	printf("%d ", root->data);
	preorderTraverse(root->left);
	preorderTraverse(root->right);
}
void inorderTraverse(node* root){
	if(root==NULL){
		return;
	}
	inorderTraverse(root->left);
	printf("%d ", root->data);
	inorderTraverse(root->right);
}
void postorderTraverse(node* root){
	if(root==NULL){
		return;
	}
	postorderTraverse(root->left);
	postorderTraverse(root->right);
	printf("%d ", root->data);
}

void add(node* root, int data){
	node* n = (node*)malloc(sizeof(node));
	n->data=data;
	n->left=NULL;
	n->right=NULL;
	node* prev = NULL;
	node* temp = root;
	while(temp!=NULL){
		if(temp->data==data){
			return;
		}
		prev = temp;
		if(data<temp->data){
			temp=temp->left;
		}else if(data>temp->data){
			temp=temp->right;
		}
	}
	if(data<prev->data){
		prev->left=n;
	}else{
		prev->right=n;
	}
}
