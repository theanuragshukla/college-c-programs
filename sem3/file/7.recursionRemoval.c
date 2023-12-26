#include<stdio.h>
#include<stdlib.h>
typedef struct Tree{
	int val;
	struct Tree * left;
	struct Tree * right;
}Tree;
#define size 100
typedef struct Stack {
	int top;
	Tree* arr[size];
}Stack;
Stack st;
void push(Tree *val){
	if(st.top==size-1){
		printf("Overflow");
	}
	else{
		st.top++;
		st.arr[st.top]=val;
	}
}
Tree* pop(){
	Tree* peek=NULL;
	if(st.top==-1){
		printf("Stack underflow");
		return NULL;
	}
	else{
		peek=st.arr[st.top];
		st.top--;
	}
	return peek;
}
int empty(){
	if(st.top==-1){
		return 1;
	}
	return 0;
}
void StaticTree(Tree **root){
	(*root)->val=23;
	Tree* newNode=(Tree*)malloc(sizeof(Tree));
	newNode->left=NULL;
	newNode->right=NULL;
	newNode->val=24;
	(*root)->left=newNode;
	Tree* newNode2=(Tree*)malloc(sizeof(Tree));
	newNode2->left=NULL;
	newNode2->right=NULL;
	newNode2->val=25;
	(*root)->right=newNode2;
	Tree* newNode3=(Tree*)malloc(sizeof(Tree));
	newNode3->left=NULL;
	newNode3->right=NULL;
	newNode3->val=26;
	newNode->left=newNode3;
	Tree* newNode4=(Tree*)malloc(sizeof(Tree));
	newNode4->left=NULL;
	newNode4->right=NULL;
	newNode4->val=27;
	newNode->right=newNode4;
}
void InOrder(Tree * ptr){
	st.top=-1;
	while(!empty()||ptr!=NULL){
		while(ptr){
			push(ptr);
			ptr=ptr->left;
		}
		ptr=pop();
		printf("%d\t",ptr->val);
		ptr=ptr->right;
	}
}
int main(){
	Tree* root;
	StaticTree(&root);
	Tree* prr=root;
	InOrder(prr);
}
