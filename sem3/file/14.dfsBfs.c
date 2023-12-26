#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50

struct node {
  int vertex;
  struct node* next;
};

struct graph {
  int numVertices;
  struct node* adjLists[MAX_VERTICES];
};

struct graph* createGraph(int vertices) {
  struct graph* g = malloc(sizeof(struct graph));
  g->numVertices = vertices;
  for (int i = 0; i < vertices; i++) {
	g->adjLists[i] = malloc(sizeof(struct node));
	g->adjLists[i]->vertex = i;
	g->adjLists[i]->next = NULL;
  }
  return g;
}

void addEdge(struct graph* g, int src, int dest) {
  struct node* newNode = malloc(sizeof(struct node));
  newNode->vertex = dest;
  newNode->next = g->adjLists[src];
  g->adjLists[src] = newNode;
}

void printGraph(struct graph* g) {
  for (int i = 0; i < g->numVertices; i++) {
	struct node* current = g->adjLists[i];
	printf("Vertex %d: ", i);
	while (current != NULL) {
  	printf("%d ", current->vertex);
  	current = current->next;
	}
	printf("\n");
  }
}

void bfs(struct graph* g, int startVertex) {
  int visited[MAX_VERTICES] = {0};
  struct node* queue = malloc(sizeof(struct node));
  queue->vertex = startVertex;
  queue->next = NULL;
  visited[startVertex] = 1;
  while (queue != NULL) {
	struct node* current = queue;
	queue = queue->next;
	int currentVertex = current->vertex;
	printf("Visited %d\n", currentVertex);
	for (struct node* temp = g->adjLists[currentVertex]; temp != NULL; temp = temp->next) {
  	int adjVertex = temp->vertex;
  	if (!visited[adjVertex]) {
    	visited[adjVertex] = 1;
    	struct node* newNode = malloc(sizeof(struct node));
    	newNode->vertex = adjVertex;
    	newNode->next = queue;
    	queue = newNode;
  	}
	}
  }
}

void dfs(struct graph* g, int vertex, int visited[]) {
  visited[vertex] = 1;
  printf("Visited %d\n", vertex);
  for (struct node* temp = g->adjLists[vertex]; temp != NULL; temp = temp->next) {
	int adjVertex = temp->vertex;
	if (!visited[adjVertex]) dfs(g, adjVertex, visited);
  }
}
int main() {
  int vertices, edges, choice, startVertex;
  printf("Enter the number of vertices and edges: ");
  scanf("%d %d", &vertices, &edges);
  struct graph* g = createGraph(vertices);
  int visited[vertices];
  for (int i = 0; i < edges; i++) {
	int src, dest;
	printf("Enter edge %d: ", i + 1);
	scanf("%d %d", &src, &dest);
	addEdge(g, src, dest);
  }
  printGraph(g);
  printf("Enter the start vertex for BFS/DFS: ");
  scanf("%d", &startVertex);
  printf("Enter 1 for BFS, 2 for DFS: ");
  scanf("%d", &choice);
  if (choice == 1) bfs(g, startVertex);
  else dfs(g, startVertex, visited);
  return 0;
}
