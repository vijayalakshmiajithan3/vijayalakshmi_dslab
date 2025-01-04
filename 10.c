#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

typedef struct {
    int items[MAX_VERTICES];
    int front;
    int rear;
} Queue;


void initializeQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}


bool isEmpty(Queue *q) {
    return (q->front == -1);
}


void enqueue(Queue *q, int value) {
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = value;
}


int dequeue(Queue *q) {
    int value = q->items[q->front];
    q->front++;
    if (q->front > q->rear) {
        initializeQueue(q);
    }
    return value;
}

void bfs(int graph[MAX_VERTICES][MAX_VERTICES], int startVertex, bool visited[MAX_VERTICES], int numVertices) {
    Queue q;
    initializeQueue(&q);

    printf("BFS Traversal: ");

    printf("%d ", startVertex);
    visited[startVertex] = true;
    enqueue(&q, startVertex);

    while (!isEmpty(&q)) {
        int currentVertex = dequeue(&q);

        for (int i = 0; i < numVertices; ++i) {
            if (graph[currentVertex][i] == 1 && !visited[i]) {
                printf("%d ", i);
                visited[i] = true;
                enqueue(&q, i);
            }
        }
    }
}

int main() {
    int numVertices;

    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    int graph[MAX_VERTICES][MAX_VERTICES];

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            scanf("%d", &graph[i][j]);
        }
    }

    
    bool visited[MAX_VERTICES];
    for (int i = 0; i < numVertices; ++i) {
        visited[i] = false;
    }

    bfs(graph, 0, visited, numVertices);
return 0;
}