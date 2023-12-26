#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

struct Node *head = NULL;

void insert(int data) {
  struct Node *new_node = malloc(sizeof(struct Node));
  new_node->data = data;

  if (head == NULL) {
	head = new_node;
	new_node->next = head;
  } else {
	struct Node *current = head;
	while (current->next != head) {
  	current = current->next;
	}
	current->next = new_node;
	new_node->next = head;
  }
}

void delete(int data) {
  if (head == NULL) {
	return;
  }

  if (head->data == data && head->next == head) {
	free(head);
	head = NULL;
  } else {
	struct Node *current = head;
	while (current->next != head && current->next->data != data) {
  	current = current->next;
	}

	if (current->next == head) {
  	return;
	}

	struct Node *temp = current->next;
	current->next = temp->next;
	free(temp);
  }
}

void print() {
  if (head == NULL) {
	return;
  }

  struct Node *current = head;
  do {
	printf("%d ", current->data);
	current = current->next;
  } while (current != head);
}

int main() {
  int command;
  int data, x=1;

  while (x) {
	printf("Enter a command (1: insert, 2: delete, 3: print, 4: quit): ");
	scanf("%d", &command);

	(command == 1) ? (printf("Enter an integer to insert: "), scanf("%d", &data), insert(data)) :
	(command == 2) ? (printf("Enter an integer to delete: "), scanf("%d", &data), delete(data)) :
	(command == 3) ? (print(), printf("\n")) :
	(command == 4) ? (x=0) : (printf("Invalid command.\n"));
  }

  return 0;
}
