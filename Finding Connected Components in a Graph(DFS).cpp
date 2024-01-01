
#include <stdio.h>
#include <stdbool.h>
#define MAX_VERTICES 100
int vertices;
int adj_matrix[MAX_VERTICES][MAX_VERTICES];
bool visited[MAX_VERTICES];
void dfs(int vertex) {
visited[vertex] = true;
for (int i = 0; i < vertices; i++) {
if (adj_matrix[vertex][i] == 1 && !visited[i]) {
dfs(i);
}
}
}
void connected_components() {
int count = 0;
for (int i = 0; i < vertices; i++) {
visited[i] = false;
}
for (int i = 0; i < vertices; i++) {
if (!visited[i]) {
dfs(i);
count++;
}
}
printf("The connected components in the graph are: %d\n", count);
}
int main() {
vertices = 8;

adj_matrix[0][1] = adj_matrix[0][2] = adj_matrix[0][3] = 1;

adj_matrix[1][0] = adj_matrix[1][2] = adj_matrix[1][4] = 1;
adj_matrix[2][0] = adj_matrix[2][1] = 1;
adj_matrix[3][4] = adj_matrix[3][5] = 1;
adj_matrix[4][2] = adj_matrix[4][3] = adj_matrix[4][5] = 1;
adj_matrix[5][3] = adj_matrix[5][4] = 1;
adj_matrix[6][7] = adj_matrix[7][6] = 1;
connected_components();
return 0;
}
