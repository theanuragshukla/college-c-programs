#include<stdio.h>
#include<stdlib.h>
typedef struct node node ;
typedef struct doublyLL dll ;
struct node{
	int data;
	node *next;
	node *prev;
};
struct doublyLL{
	node *head;
	node *tail;
};

void printLinkedist(dll *ll);
dll* insertNodeAt(dll *head,int idx,  int val);
dll* deleteNodeAt(dll *head,int idx);

int main(){
	int n = 10;
	dll *ll;
	ll = insertNodeAt(ll, 0, -1);
	printLinkedist(ll);
	ll = insertNodeAt(ll, 8, 67);
	printLinkedist(ll);
	ll = insertNodeAt(ll, 5, -656);
	printLinkedist(ll);
	ll=deleteNodeAt(ll, 0);
	printLinkedist(ll);
	ll=deleteNodeAt(ll, 8);
	printLinkedist(ll);
	ll=deleteNodeAt(ll, 5);
	printLinkedist(ll);
	return 0;
}
void printLinkedist(dll *ll){
	printf("\n");
	node *head = ll->head;
	while(head!=NULL){
		printf("%d ", head->data);
		head=head->next;
	}
	free(head);
}


dll* insertNodeAt(dll *ll,int idx,  int val){
	if(idx==0){
		return addFirst(ll, val);
	}
	int count = 0;
	node *temp = ll->head;
	while(temp!=NULL){
		if(count==idx-1){
			node *newNode = (node *)malloc(sizeof(node));
			newNode->data = val;
			newNode->next = temp->next;
			temp->next=newNode;
			newNode->prev = temp;
			temp->next->prev=newNode;
			break;
		}
		temp=temp->next;
		count++;
	}
	return ll;
}

dll* deleteNodeAt(dll *ll,int idx){
	if(idx==0)return deleteFirst(ll);
	int count = 0;
	node *temp = ll->head;
	while(temp!=NULL){
		if(count==idx-1){
			node *toFree = temp->next;
			temp->next=toFree->next;
			temp->next->prev=temp;
			free(toFree);
			break;
		}
		temp=temp->next;
		count++;
	}

	return ll;
}


