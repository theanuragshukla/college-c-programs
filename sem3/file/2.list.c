#include <stdio.h>
#define MAX_SIZE 100
typedef struct {
  int items[MAX_SIZE];
  int size;
} List;
void init(List *list) {
  list->size = 0;
}
void insert(List *list, int index, int value) {
  if (list->size == MAX_SIZE) {
	printf("Error: List is full\n");
	return; }
  if (index < 0 || index > list->size) {
	printf("Error: Invalid index\n");
	return;}
  for (int i = list->size; i > index; i--) {
	list->items[i] = list->items[i - 1];}
  list->items[index] = value;
  list->size++;
}
void removeElem(List *list, int index) {
  if (index < 0 || index >= list->size) {
	printf("Error: Invalid index\n");
	return; }
  for (int i = index; i < list->size - 1; i++) {
	list->items[i] = list->items[i + 1];}
  list->size--;
}
int get(List *list, int index) {
  if (index < 0 || index >= list->size) {
	printf("Error: Invalid index\n");
	return -1; }
  return list->items[index];
}
int main() {
  List list;
  init(&list);
  insert(&list, 0, 10); insert(&list, 0, 20); insert(&list, 1, 30);
  printf("%d %d %d\n", get(&list, 0), get(&list, 1), get(&list, 2));
  removeElem(&list, 1);
  printf("%d\n", get(&list, 1));
  return 0;
}
