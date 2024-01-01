#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define INF 9999999
typedef struct Edge {
int src, dest, weight;
} Edge;
typedef struct Graph {
int V, E;
Edge* edge;
} Graph;
Graph* createGraph(int V, int E) {
Graph* graph = (Graph*) malloc(sizeof(Graph));
graph->V = V;
graph->E = E;
graph->edge = (Edge*) malloc(E * sizeof(Edge));
return graph;
}
int getNode(char node, Graph* graph) {
for (int i = 0; i < graph->V; i++)
if (node == 'A' + i)
return i;
return -1;
}
void Dijkstra(Graph* graph, int src) {
int dist[graph->V];
int visited[graph->V];
for (int i = 0; i < graph->V; i++) {
dist[i] = INF;
visited[i] = 0;
}

dist[src] = 0;
for (int i = 0; i < graph->V - 1; i++) {
int u = -1;
for (int j = 0; j < graph->V; j++)
if (!visited[j] && (u == -1 || dist[j] < dist[u]))
u = j;
visited[u] = 1;
for (int v = 0; v < graph->V; v++) {
int weight = INF;
for (int k = 0; k < graph->E; k++) {
if (graph->edge[k].src == u && graph->edge[k].dest == v) {
weight = graph->edge[k].weight;
break;
}
}
if (dist[u] != INF && dist[u] + weight < dist[v])
dist[v] = dist[u] + weight;
}
}
for (int i = 0; i < graph->V; i++)
printf("Shortest distance from %c to %c is: %d\n", 'A' + src, 'A' + i, dist[i]);
}
int main() {
int V = 7;
int E = 13;
Graph* graph = createGraph(V, E);

graph->edge[0].src = 0;
graph->edge[0].dest = 1;
graph->edge[0].weight = 5;
graph->edge[1].src = 1;
graph->edge[1].dest = 2;

graph->edge[1].weight = 3;
graph->edge[2].src = 1;
graph->edge[2].dest = 3;
graph->edge[2].weight = 7;
graph->edge[3].src = 2;
graph->edge[3].dest = 4;
graph->edge[3].weight = 4;
graph->edge[4].src = 3;
graph->edge[4].dest = 5;
graph->edge[4].weight = 8;
graph->edge[5].src = 4;
graph->edge[5].dest = 6;
graph->edge[5].weight = 6;
graph->edge[6].src = 5;
graph->edge[6].dest = 6;
graph->edge[6].weight = 5;

char src = 'A';
char dest = 'G';
int src_node = getNode(src, graph);
int dest_node = getNode(dest, graph);
Dijkstra(graph, src_node);
return 0;
}
