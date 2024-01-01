#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_VERTICES 100
typedef struct {
int vertices;
int matrix[MAX_VERTICES][MAX_VERTICES];
} Graph;
typedef struct {
int index;
int distance;
} Vertex;
int compare(const void *a, const void *b) {
Vertex *vertex_a = (Vertex *)a;
Vertex *vertex_b = (Vertex *)b;
return vertex_b->distance - vertex_a->distance;
}
Graph *create_graph(int vertices) {
Graph *graph = (Graph *)malloc(sizeof(Graph));
graph->vertices = vertices;
for (int i = 0; i < vertices; i++) {
for (int j = 0; j < vertices; j++) {
graph->matrix[i][j] = 0;
}
}
return graph;
}
void add_edge(Graph *graph, int source, int destination) {
graph->matrix[source][destination] = 1;
}
void bfs(Graph *graph, int start, int end) {

int distance[MAX_VERTICES];
int queue[MAX_VERTICES];
int queue_size = 0;
int queue_head = 0;
for (int i = 0; i < graph->vertices; i++) {
distance[i] = -1;
}
distance[start] = 0;
queue[queue_size++] = start;
while (queue_size != 0) {
int current = queue[queue_head++];
if (current == end) {
break;
}
for (int i = 0; i < graph->vertices; i++) {
if (graph->matrix[current][i] == 1 && distance[i] == -1) {
distance[i] = distance[current] + 1;
queue[queue_size++] = i;
}
}
}
if (distance[end] == -1) {
printf("No path from %c to %c\n", start + 'A', end + 'A');
} else {
printf("The shortest path from %c to %c is: ", start + 'A', end + 'A');
int path_index = end;
while (path_index != start) {
printf("%c -> ", path_index + 'A');
for (int i = 0; i < graph->vertices; i++) {
if (graph->matrix[i][path_index] == 1 && distance[i] == distance[path_index] - 1) {
path_index = i;
break;

}
}
}
printf("%c\n", start + 'A');
}
}
int main() {
Graph *graph = create_graph(7);
add_edge(graph, 0, 1);
add_edge(graph, 1, 2);
add_edge(graph, 1, 3);
add_edge(graph, 2, 4);
add_edge(graph, 3, 5);
add_edge(graph, 4, 6);
add_edge(graph, 5, 6);
add_edge(graph, 6, 6);
bfs(graph, 0, 6);
return 0;
}
