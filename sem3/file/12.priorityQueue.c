#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
typedef struct {
  int priority;
  int value;
} Item;

typedef struct {
  Item items[MAX_SIZE];
  int size;
} PriorityQueue;

void init(PriorityQueue *queue) {
  queue->size = 0;
}

int is_empty(PriorityQueue *queue) {
  return queue->size == 0;
}

void insert(PriorityQueue *queue, int value, int priority) {
  if (queue->size == MAX_SIZE) {
	printf("Error: Queue is full\n");
	return;
  }
  Item new_item;
  new_item.value = value;
  new_item.priority = priority;
  int i = queue->size;
  while (i > 0 && queue->items[i - 1].priority > priority) {
	queue->items[i] = queue->items[i - 1];
	i--;
  }
  queue->items[i] = new_item;
  queue->size++;
}

int pop(PriorityQueue *queue) {
  if (is_empty(queue)) {
	printf("Error: Queue is empty\n");
	return -1;
  }
  int value = queue->items[queue->size - 1].value;
  queue->size--;
  return value;
}

int main() {
  PriorityQueue queue;
  init(&queue);
  insert(&queue, 10, 1);
  insert(&queue, 20, 2);
  insert(&queue, 30, 0);
  printf("%d\n", pop(&queue)); 
  printf("%d\n", pop(&queue));
  printf("%d\n", pop(&queue));
  return 0;
}
