#include<stdio.h>
#include<stdbool.h>
#define MAX_VERTICES 100
void dfs(int graph[MAX_VERTICES][MAX_VERTICES],
	int vertex, bool visited[MAX_VERTICES],int numVertices)
{
	printf("%d ",vertex);
	visited[vertex] = true;
	for(int i = 0;i < numVertices;++i)
	{
		if(graph[vertex][i] == 1 &&! visited[i])
		{
			dfs(graph,i,visited,numVertices);
		}
	}
}

int main()
{
	int numVertices;
	printf("Enter the number of vertices : ");
	scanf("%d",&numVertices);
	int graph[MAX_VERTICES][MAX_VERTICES];
	printf("Enter the adjancency matrix : \n");
	for(int i=0;i < numVertices;++i)
	{
		for(int j=0;j < numVertices;++j)
		{
			scanf("%d",&graph[i][j]);
		}
	}
	bool visited[MAX_VERTICES];
	for(int i=0;i<numVertices;++i)
	{
		visited[i] = false;
	}
	printf("DFS Traversal:");
	dfs(graph,0,visited,numVertices);
	return 0;
}