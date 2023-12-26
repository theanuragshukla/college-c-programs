#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_QUEUE_SIZE 5

typedef struct queue_t {
	int entry[MAX_QUEUE_SIZE];
	int front;
	int rear;
} queue_t;

void init_queue(queue_t* q){
	q->front = q->rear = 0;
}

bool is_queue_empty(queue_t* q){
	return q->front == q->rear;
}
bool is_queue_full(queue_t* q){
	return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;
}

void enqueue(queue_t* q, int data){
	if (is_queue_full(q)) {
		printf("Error: queue is full!\n");
		return;
	}
	q->entry[q->rear] = data;
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
}

int dequeue(queue_t* q){
	if (is_queue_empty(q)) {
		printf("Error: queue is empty!\n");
		exit(EXIT_FAILURE);
	}

	int data = q->entry[q->front];
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return data;
}

int main(void){
	queue_t q;
	init_queue(&q);

	enqueue(&q, 1);
	enqueue(&q, 2);
	enqueue(&q, 3);
	enqueue(&q, 4);
	enqueue(&q, 5);
	enqueue(&q, 6);

	while (!is_queue_empty(&q)) {
		printf("%d ", dequeue(&q));
	}
	printf("\n");

	return 0;
}
