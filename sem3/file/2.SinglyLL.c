#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

struct Node *head = NULL;

void insert_at_beginning(int value) {
  struct Node *new_node = (struct Node*) malloc(sizeof(struct Node));
  new_node->data = value;
  new_node->next = head;
  head = new_node;
}

void insert_at_end(int value) {
  struct Node *new_node = (struct Node*) malloc(sizeof(struct Node));
  new_node->data = value;
  new_node->next = NULL;
  
  if (head == NULL) {
    head = new_node;
    return;
  }
  
  struct Node *current_node = head;
  while (current_node->next != NULL) {
    current_node = current_node->next;
  }
  
  current_node->next = new_node;
}

void delete_node(int value) {
  struct Node *current_node = head;
  struct Node *previous_node = NULL;
  
  if (current_node != NULL && current_node->data == value) {
    head = current_node->next;
    free(current_node);
    return;
  }
  
  while (current_node != NULL && current_node->data != value) {
    previous_node = current_node;
    current_node = current_node->next;
  }
  
  if (current_node == NULL) {
    return;
  }
  
  previous_node->next = current_node->next;
  free(current_node);
}

void print_linked_list() {
  struct Node *current_node = head;
  while (current_node != NULL) {
    printf("%d ", current_node->data);
    current_node = current_node->next;
  }
  printf("\n");
}

int main() {
  insert_at_beginning(3);
  insert_at_beginning(2);
  insert_at_beginning(1);
  insert_at_end(4);
  insert_at_end(5);
  print_linked_list();
  delete_node(3);
  print_linked_list();
  return 0;
}
