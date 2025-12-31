#include <stdio.h>

int graph[20][20], visited[20], n;


void DFS(int v)
{
    visited[v] = 1;
    for (int i = 0; i < n; i++)
    {
        if (graph[v][i] == 1 && !visited[i])
        {
            DFS(i);
        }
    }
}

int main()
{
    int start = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Enter %d %d element \t: ",i,j);
            scanf("%d", &graph[i][j]);
        }
    }


    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }


    DFS(start);


    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            printf("Graph is NOT connected\n");
            return 0;
        }
    }

    printf("Graph is CONNECTED\n");
    return 0;
}
