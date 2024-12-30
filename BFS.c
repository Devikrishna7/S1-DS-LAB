#include <stdio.h>
#define MAX 10
int adj[MAX][MAX], num, visited[MAX] = {0}, queue[MAX], F = -1, R = -1;
int read()
{
    printf("enter the number of vertices: ");
    scanf("%d", &num);
    printf("enter the adjacency matrices:\n");
    for (int i = 1; i <= num; i++)
        for (int j = 1; j <= num; j++)
            scanf("%d", &adj[i][j]);
    return 1;
}
void bfs(int x) // passing starting vertex
{
    printf("BFS\n");
    F = R = 1;
    queue[R] = x;
    visited[x] = 1;
    printf("%d",x);
    while (F <= R)
    {
        x = queue[F];
        F = F + 1;
        for(int j=1;j<=num;j++){
            if(adj[x][j]==1 &&  !visited[j]){
                printf("%d ",j);
                visited[j]=1;
                R+=1;
                queue[R]=j;
            }
        }
    }
}
void main()
{
    int x;
    read();
    printf("enter the starting vertex: ");
    scanf("%d", &x);
    bfs(x);
}
