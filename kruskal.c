#include <stdio.h>
#define MAX 100
int parent[MAX];
// Function to find the parent of a node
int find(int i) {
while (parent[i] != i)
i = parent[i];
return i;
}
// Function to perform union of two subsets
void unionSets(int u, int v) {
int rootU = find(u);
int rootV = find(v);
parent[rootU] = rootV;
}
// Kruskal's Algorithm
void kruskal(int graph[MAX][MAX], int V) {
int minCost = 0, edges = 0;
// Initialize parent array for union-find
for (int i = 0; i < V; i++)
parent[i] = i;
printf("Edges in the Minimum Spanning Tree:\n");
// Keep finding the minimum edge until we have V-1 edges
while (edges < V - 1) {
int min = 999, u = -1, v = -1;
// Find the minimum edge in the graph
for (int i = 0; i < V; i++) {
for (int j = 0; j < V; j++) {
if (graph[i][j] != 0 && graph[i][j] < min && find(i) != find(j)) {
min = graph[i][j];
u = i;
v = j;
}
}
}
// Include this edge in the MST
unionSets(u, v);
printf("%d -- %d == %d\n", u, v, min);
minCost += min;
edges++;
// Mark the edge as used by setting its weight to 0
graph[u][v] = graph[v][u] = 0;
}
printf("Total cost of MST: %d\n", minCost);
}
int main() {
int V, graph[MAX][MAX];
printf("Enter the number of vertices: ");
scanf("%d", &V);
printf("Enter the adjacency matrix:\n");
for (int i = 0; i < V; i++) {
for (int j = 0; j < V; j++) {
scanf("%d", &graph[i][j]);
}
}
kruskal(graph, V);
return 0;
}
