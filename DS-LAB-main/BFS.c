#include<stdio.h>
int graph[20][20],visited[20],n;
void BFS(int start) {
    int queue[20],f=0,r=0;
    visited[start]=1;
    queue[r++]=start;
    while (f<r) {
        int node=queue[f++];
        printf("%d",node);
        for (int i=0;i<n;i++) {
            if (graph[node][i]==1&&!visited[i]) {
                visited[i]=1;
                queue[r++]=i;
            }

        }
    }

}
int main() {
    int start;
    printf("Enter number of vertices : ");
    scanf("%d",&n);
    printf("Enter Adjacency Matrix : ");
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            printf("Enter %d %d element \n: ",i,j);
            scanf("%d",&graph[i][j]);

        }
    }
    for (int i=0;i<n;i++) {
        visited[i]=0;
    }
    printf("Enter the starting element : ");
    scanf("%d",&start);
    printf("BFS Traversal : ");
    BFS(start);
    return 0;
}
