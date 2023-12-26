#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insert(int data, int position) {
    struct Node* newNode = malloc(sizeof *newNode);
    newNode->data = data;

    if (position == 0) {
        newNode->next = head;
        head = newNode;
        return;
    }

    struct Node* current = head;
    for (int i = 0; i < position-1; i++) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

void delete(int position) {
    if (position == 0) {
        head = head->next;
        return;
    }

    struct Node* current = head;
    for (int i = 0; i < position-1; i++) {
        current = current->next;
    }

    current->next = current->next->next;
}

void print() {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
