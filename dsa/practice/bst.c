#include <stdio.h>
#include <stdlib.h>

typedef struct node node ;

struct node {
	int data;
	node *left;
	node * right;
};

node * newNode(int val){
	node *temp = (node*)malloc(sizeof(node));
	temp->data=val;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

node* insert(node * root, int val){
	if(root==NULL)return newNode(val);

	if(root->data>val){
		root->left = insert(root->left, val);
	}else if(root->data<val){
		root->right = insert(root->right, val);
	}else{
		return root;
	}
	return root;
}

 node * inorderSuccesor(node * root){
	 while(root && root->left){
		 root=root->left;
	 }
	 return root;
 }

node * delete(node* root, int val){
	if(root==NULL)return root;
	if(root->data>val){
		root->left = delete(root->left,val);
	}else if(root->data < val){
		root->right = delete(root->right,val);
	}else{
		if(root->left==NULL && root->right==NULL){
			node * temp = root;
			free(temp);
			return NULL;
		}else if(root->left==NULL){
			node * temp = root->right;
			free(root);
			return temp;
		}else if(root->right==NULL){
			node * temp = root->left;
			free(root);
			return temp;
		}
		else {
			node * temp = inorderSuccesor(root->right);
			root->data = temp->data;
			free(temp);
		}
	}
	return root;
}


void inorder(node*root){
	if(root==NULL)return;
	inorder(root->left);
	printf("%d ", root->data);
	inorder(root->right);
}

int main (){
	node * root;
	root = insert(root, 1);
	insert(root, 4);
	insert(root, 6);
	insert(root, 3);
	insert(root, 8);
	insert(root, 10);
	insert(root, 2);
	insert(root, 5);
	delete(root, 3);
	delete(root, 5);
	insert(root, 7);
	insert(root, 9);
	root = delete(root, 1);
	inorder(root);
	return 0;
}
