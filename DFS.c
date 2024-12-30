#include<stdio.h>
#define MAX 10
// stack, top of stack, adjacency matrix, visted vertices,number of vertices
int stk[MAX], top = -1, adj[MAX][MAX] = {0}, visted[MAX] = {0}, num;


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
void dfs(int start)
{
    int curV = start;
    visted[curV] = 1;
    printf("%d ", curV);
    stk[++top] = curV;
    while (top!=-1)
    {
        for (int i = 1; i <= num; i++)
        {
            if (adj[curV][i] && !visted[i])
            {
                curV = i;
                printf("%d ", curV);
                stk[++top] = curV;
                visted[curV] = 1;
            }
        }
        curV = stk[--top];
    }
}

int main()
{
    int start;
    read();
    printf("Enter the starting vertex: ");
    scanf("%d", &start);
    dfs(start);
}