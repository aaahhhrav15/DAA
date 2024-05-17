#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

int minKey(int n,int key[], bool mstSet[])
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < n; v++)
    {
        if (mstSet[v] == false && key[v] < min)
        {
            min = key[v], min_index = v;
        }
    }

    return min_index;
}

void display(int n,int parent[], int graph[n][n])
{
    int sum=0;
    printf("Edge \tWeight\n");
    for (int i = 1; i < n; i++)
    {
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
        sum+=graph[i][parent[i]];
    }
    printf("Minimum cost is %d",sum);
}

void prims(int n,int graph[n][n])
{
    int parent[n];
    int key[n];
    bool mstSet[n];

    for (int i = 0; i < n; i++)
    {
        key[i] = INT_MAX, mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < n - 1; count++) 
    {
        int u = minKey(n,key, mstSet);
        mstSet[u] = true;
        for (int v = 0; v < n; v++)
        {
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
            {
                parent[v] = u, key[v] = graph[u][v];
            }
        }
    }

    display(n,parent, graph);
}

int main()
{
    int n;
    printf("Enter the number of vertices\n");
    scanf("%d",&n);
    int graph[n][n];
    printf("Enter weights\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("Enter the weight between vertex %d and %d: ",i,j);
            scanf("%d",&graph[i][j]);
        }
    }

    prims(n,graph);
    return 0;
}
